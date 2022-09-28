/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/29 00:57:32 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**get_path(char **envp)
{
	char	**path;
	int		i;

	path = ((void *)0);
	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = ft_split(envp[i] + 5, ':');
			return (path);
		}
	}
	return (NULL);
}

char	*find_cmd_in_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (!tmp)
			return (NULL);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		else
			free(tmp);
	}
	return (NULL);
}

int	is_variable(char *command)
{
	char	**variable;
	int		i;
	int		j;
	
	i = var_iteration(1, command);
	j = var_iteration(2, command);
	if (j == 0)
		return (0);
	variable = (char **) easy_alloc(sizeof(char *) * 2);
	variable[0] = (char *) add_p(ft_substr(command, 0, j));
	variable[1] = (char *) add_p(ft_substr(command, j + 1, i));
	if (g_context->variables == NULL)
		g_context->variables = (struct t_list *) add_p(ft_lstnew(variable));
	else
	{
		if (check_repeat(variable))
			ft_lstadd_front((t_list **)&(g_context->variables),
				(t_list *) add_p(ft_lstnew(variable)));
	}
	return (1);
}

char	*replace_variables(char *cmd)
{
	char	*result;
	char	*left;
	char	*right;
	char	*postfix;

	result = (char *) add_p(ft_strdup(""));
	left = cmd;
	while (*left != '\0')
	{
		if (*left == '$')
		{
			postfix = get_postfix(&left);
			result = replace_one(postfix, result);
		}
		else
		{
			right = (char *) easy_alloc(ft_strlen(result) + 2);
			right = ft_strcpy(right, result);
			right[ft_strlen(result)] = *(left++);
			right[ft_strlen(result) + 1] = '\0';
			f_one(result);
			result = right;
		}
	}
	printf("result: %s\n", result);
	return (result);
}

t_command	*parse(char *cmd)
{
	t_command	*command;

	while (*cmd == '\t' || *cmd == '\n' || *cmd == ' ')
		++cmd;
	if (is_variable(cmd))
		return (NULL);
	command = (t_command *)easy_alloc(sizeof(t_command));
	command->fixed_cmd = replace_variables(cmd);
	command->fullcmd = (char **) add_p(ft_split(command->fixed_cmd, ' '));
	command->cmd_exec = (char *) add_p(ft_strjoin("/", command->fullcmd[0]));
	command->cmd_path = find_cmd_in_path(g_context->path, command->cmd_exec);
	if (!command->cmd_path)
		return (parse_errors(4, command));
	else
		add_p(command->cmd_path);
	return (command);
}
