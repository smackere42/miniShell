/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 16:55:22 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//echo 1 | cat1 | cat2 | cat3
// echo 1
//stdin -> echo 1 -> stdout
//stdin -> echo 1 -> g_context->tube[1] -> g_context->tube[0] -> cat1 -> g_context->tube[1] -> g_context->tube[0]->  cat2 -> g_context->tube[1] -> g_context->tube[0]


#include "executor.h"


void close_all_pipes(int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		close(g_context->commands[j]->tube[0]);
		close(g_context->commands[j]->tube[1]);
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
		if (pipe(g_context->commands[i]->tube) == -1)
				exit(0);
		g_context->commands[i]->pid = fork();
		if (g_context->commands[i]->pid == -1)
				exit(1);
		if (g_context->commands[i]->pid == 0)
		{
			if (g_context->commands[i + 1] && g_context->commands[i + 1]->from->type == FD)
				g_context->commands[i]->to->fd = g_context->commands[i]->tube[1];
			if (i != 0 && g_context->commands[i - 1]->to->type == FD && g_context->commands[i]->from->type == FD)
				g_context->commands[i]->from->fd = g_context->commands[i - 1]->tube[0];
			//printf("fd[0] - %d\n", g_context->commands[i]->from->fd);
			//printf("fd[1] - %d\n", g_context->commands[i]->to->fd);
			redir(g_context->commands[i]);
			if (g_context->commands[i]->cmd_info->is_err)
				pexit("command not found", g_context->commands[i]->cmd_info->cmd_exec + 1, 1);
			execve(g_context->commands[i]->cmd_info->cmd_path, g_context->commands[i]->cmd_info->fullcmd, g_context->envp);
		}
		waitpid(g_context->commands[i]->pid, &g_context->last_exit_code, 0);
		close(g_context->commands[i]->tube[1]);
		if (g_context->commands[i]->pid == 0)
			exit(g_context->last_exit_code);
		++i;
	}
	close_all_pipes(c);
	//printf("OUT WHILE\n");
	return (0);
}
