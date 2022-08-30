/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/08/30 21:46:04 by smackere         ###   ########.fr       */
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

char	*get_cmd(char *cmd, char **envp)
{
	char	**path;
	char	*tmp_cmd;
	char	*tmp;

	path = get_path(envp);
	if (!path)
		return (NULL);
	tmp_cmd = ft_strjoin("/", cmd);
	if (!tmp_cmd)
		return (NULL);
	tmp = find_cmd_in_path(path, tmp_cmd);
	if (!tmp)
	{
		return (NULL);
	}
	free(path);
	free(tmp_cmd);
	return (tmp);
}
