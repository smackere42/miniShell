/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/19 22:50:53 by kmumm            ###   ########.fr       */
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
	char**	variable;
	char	sym;
	int		i = 0;
	int		j = 0;
	t_list	*temp;

	while (command[i] != '\0')
	{
		sym = command[i];
		if ((ft_isdigit(sym) || ft_isalpha(sym)) && j==0)
			++i;
		else if (sym == '=' && j==0)
			j = i;
		else if (sym == '\n' || sym == '\t' || sym == ' ')
			return 0;
		else
			++i;
	}
	if (j == 0)
		return 0;
	variable = (char **) malloc(sizeof(char *) * 2);
	variable[0] = ft_substr(command, 0, j);
	easy_addp(variable[0]);
	variable[1] = ft_substr(command, j+1, i);
	easy_addp(variable[1]);
	if (g_context->variables == NULL)
		g_context->variables = (struct t_list *) ft_lstnew(variable);
	else
	{
		temp = (t_list *)g_context->variables;
		while (temp != NULL)
		{
			if (ft_strncmp(((char **)temp->content)[0], variable[0], j-i) == 0)
			{
				free(((char **)temp->content)[0]);
				free(((char **)temp->content)[1]);
				free(temp->content);
				temp->content =(struct t_list *) variable;
				return 1;
			}
			temp = temp->next;
		}
		ft_lstadd_front((t_list **)&(g_context->variables), ft_lstnew(variable));
	}
	return 1;
}

char *replace_variable(char *str)
{
	char	*result;
	char	*temp;
	char	*temp2;
	t_list	*temp3;

	result = ft_strdup("");
	easy_addp(result);
	while (*str != '\0')
	{
		if (*str == '$')
		{
			++str;
			temp = ft_strchr(str, '$');
			if (temp == NULL)
				temp = ft_strchr(str, ' ');
			if (temp == NULL)
				temp = ft_strchr(str, '\0');
			temp2 = ft_substr(str, 0, temp - str);
			easy_addp(temp2);
			temp3 = (t_list *)g_context->variables;
			while (temp3 != NULL)
			{
				if (ft_strncmp(((char **)temp3->content)[0], temp2, temp - str) == 0)
				{
					temp = ft_strjoin(result, ((char **)temp3->content)[1]);
					easy_addp(temp);
					free(result);
					result = temp;
					break;
				}
				temp3 = temp3->next;
			}
			str = temp;
		}
		else
		{
			//printf("error123\n");
			temp = ft_strjoin(result, ft_substr(str, 0, 1));
			easy_addp(temp);
			//easy_fone(result);
			free(result);
			result = temp;
			++str;
		}
	}
	printf("%s\n", result);
	return result;
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
		return NULL;
	cmd = replace_variable(cmd);
	parsed = ft_split(cmd, ' ');
	easy_addp(parsed);
	path = get_path(envp);
	easy_addp(path);
	command->cmd = ft_strjoin("/", parsed[0]);
	easy_addp(command->cmd);
	command->cmd_path = find_cmd_in_path(path, command->cmd);
	if (!command->cmd_path)
		return (parse_errors(4, command));
	command->args = parsed;
	command->fullcmd = parsed;
	return (command);
}

