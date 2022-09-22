/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/23 01:35:13 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**get_path(char **envp)
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

static char	*find_cmd_in_path(char **path, char *cmd)
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
	t_list	*temp;

	i = var_iteration(1, command);
	j = var_iteration(2, command);
	if (j == 0)
		return (0);
	variable = (char **) malloc(sizeof(char *) * 2);
	variable[0] = (char *) easy_addp(ft_substr(command, 0, j));
	variable[1] = (char *) easy_addp(ft_substr(command, j + 1, i));
	if (g_context->variables == NULL)
		g_context->variables = (struct t_list *) ft_lstnew(variable);
	else
	{
		temp = (t_list *)g_context->variables;
		temp = list_iteration(temp, i, j, variable);
		ft_lstadd_front((t_list **)&(g_context->variables),
			ft_lstnew(variable));
	}
	return (1);
}

char	*replace_variable(char *left)
{
	char	*result;
	char	*right;
	char	*temp_cmd;
	t_list	*variables;

	result = (char *) easy_addp(ft_strdup(""));
	while (*left != '\0')
	{
		if (*left == '$')
		{
			++left;
			right = left;
			right = string_move(right);
			temp_cmd = (char *) easy_addp(ft_substr(left, 0, right - left));
			left = right;
			variables = (t_list *)g_context->variables;
			result = var_replace_counter(variables, right, temp_cmd, result);
		}
		else
		{
			right = (char *) easy_addp(ft_strjoin(result,
						ft_substr(left, 0, 1)));
			free(result);
			result = right;
			++left;
		}
	}
	return (result);
}

t_command	*parse(char *cmd, char **envp)
{
	char		**parsed;
	t_command	*command;
	char		**path;

	while (*cmd == '\t' || *cmd == '\n' || *cmd == ' ')
		++cmd;
	command = (t_command *)easy_alloc(sizeof(t_command));
	if (is_variable(cmd))
		return (NULL);
	cmd = replace_variable(cmd);
	parsed = (char **)easy_addp(ft_split(cmd, ' '));
	path = (char **)easy_addp(get_path(envp));
	command->cmd = (char *) easy_addp(ft_strjoin("/", parsed[0]));
	command->cmd_path = find_cmd_in_path(path, command->cmd);
	if (!command->cmd_path)
		return (parse_errors(4, command));
	command->args = parsed;
	command->fullcmd = parsed;
	return (command);
}
