/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/01 03:13:35 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//int parse_args(char **argv)
//{

//}

//int parse_command(char *command)
//{

//}

//static void ps_error(char *error_string)
//{
//	ft_putstr(error_string);
//	exit(0);
//}

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

t_command	*parse(char *cmd, char **envp)
{
	char		**parsed;
	t_command	*command;
	char		**path;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (parse_errors(0, command));
	parsed = ft_split(cmd, ' ');
	if (!parsed)
		return (parse_errors(1, command));
	path = get_path(envp);
	if (!path)
		return (parse_errors(2, command));
	command->cmd = ft_strjoin("/", parsed[0]);
	if (!command->cmd)
		return (parse_errors(3, command));
	command->cmd_path = find_cmd_in_path(path, command->cmd);
	if (!command->cmd_path)
		return (parse_errors(4, command));
	command->args = ++parsed;
	command->fullcmd = parsed;
	return (command);
}
