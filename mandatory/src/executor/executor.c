/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:16:38 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	close_all_pipes(int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		close(g_con->coms[j]->tube[0]);
		close(g_con->coms[j]->tube[1]);
		j++;
	}
}

int	exec_command(char *read)
{
	int			c;
	int			i;

	c = parse_pipes(read);
	if (!c)
		return (0);
	i = 0;
	while (i != c)
	{
		if (pipe(g_con->coms[i]->tube) == -1)
			exit(0);
		g_con->coms[i]->pid = fork();
		if (g_con->coms[i]->pid == -1)
			exit(1);
		if (g_con->coms[i]->pid == 0)
		{
			if (g_con->coms[i + 1] && g_con->coms[i + 1]->from->type == FD)
				g_con->coms[i]->to->fd = g_con->coms[i]->tube[1];
			if (i != 0 && g_con->coms[i - 1]->to->type == FD
				&& g_con->coms[i]->from->type == FD)
				g_con->coms[i]->from->fd = g_con->coms[i - 1]->tube[0];
			redir(g_con->coms[i]);
			if (g_con->coms[i]->cmd_info->is_err)
				pexit("command not found",
					g_con->coms[i]->cmd_info->cmd_exec + 1, 1);
			execve(g_con->coms[i]->cmd_info->cmd_path,
				g_con->coms[i]->cmd_info->fullcmd, g_con->envp);
		}
		waitpid(g_con->coms[i]->pid, &g_con->last_exit_code, 0);
		close(g_con->coms[i]->tube[1]);
		if (g_con->coms[i]->pid == 0)
			exit(g_con->last_exit_code);
		++i;
	}
	close_all_pipes(c);
	return (0);
}
