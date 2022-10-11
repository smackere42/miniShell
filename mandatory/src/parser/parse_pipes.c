/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:40:36 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 08:15:04 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int parse_pipes(char *read)
{
	char		**c;
	int			len;
	int			i;

	c = add_p(ft_split(read, '|'));
	if (!c)
		return (0);
	len = ft_split_len(c);
	i = 0;
	g_context->commands = easy_alloc(sizeof(t_command *) * (len + 1));
	g_context->commands[len] = NULL;
	while (c[i])
	{
		g_context->commands[i] = easy_alloc(sizeof(t_command *));
		g_context->commands[i]->pid = -1;
		g_context->commands[i]->cmd_info = parse(add_p(c[i]));
		g_context->commands[i]->from = easy_alloc(sizeof(t_redirect *));
		g_context->commands[i]->to = easy_alloc(sizeof(t_redirect *));
		g_context->commands[i]->from->type = FD;
		g_context->commands[i]->from->fd = 0;
		g_context->commands[i]->to->type = FD;
		g_context->commands[i]->to->fd = 1;
		if (ft_strncmp(c[i], "", ft_strlen(c[i])) == 0)
		{
			f_split(c);
			return (0);
		}
		++i;
	}
	for (int i = 0; g_context->commands[i]; i++)
	{
		printf("cmd: %s\n", g_context->commands[i]->cmd_info->cmd_exec);
	}

	return (len);
}