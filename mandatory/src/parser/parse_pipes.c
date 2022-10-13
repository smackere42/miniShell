/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:40:36 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:15:26 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_command(int i, char *cmd_inf)
{
	g_con->coms[i] = (t_command *) easy_alloc(sizeof(t_command *));
	g_con->coms[i]->pid = -1;
	g_con->coms[i]->cmd_info = parse(add_p(cmd_inf));
	g_con->coms[i]->from = (t_redir *) easy_alloc(sizeof(t_redir *));
	g_con->coms[i]->to = (t_redir *) easy_alloc(sizeof(t_redir *));
	g_con->coms[i]->from->type = FD;
	g_con->coms[i]->from->fd = 0;
	g_con->coms[i]->to->type = FD;
	g_con->coms[i]->to->fd = 1;
}

void	free_commands(t_command **command, int i)
{
	while (--i > 0)
	{
		f_cmd_info(command[i]->cmd_info);
		f_one(command[i]->from);
		f_one(command[i]->to);
		f_one(command[i]);
	}
	f_one(command);
}

int	init_all_commands(char **c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_split_len(c);
	g_con->coms = easy_alloc(sizeof(t_command *) * (len + 1));
	g_con->coms[len] = NULL;
	while (c[i])
	{
		init_command(i, c[i]);
		if (ft_strncmp(c[i], "", ft_strlen(c[i])) == 0)
		{
			free_commands(g_con->coms, i);
			return (0);
		}
		++i;
	}
	g_con->coms[i] = NULL;
	return (len);
}

int	parse_pipes(char *read)
{
	char		**c;
	int			len;

	c = add_p(ft_split(read, '|'));
	if (!c)
		return (0);
	len = init_all_commands(c);
	if (!len)
		return (0);
	return (len);
}
