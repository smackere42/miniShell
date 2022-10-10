/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 00:35:25 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//echo 1 | cat1 | cat2 | cat3
// echo 1
//stdin -> echo 1 -> stdout
//stdin -> echo 1 -> g_context->tube[1] -> g_context->tube[0] -> cat1 -> g_context->tube[1] -> g_context->tube[0]->  cat2 -> g_context->tube[1] -> g_context->tube[0]


#include "executor.h"

int	exec_command(char *read)
{
	int			c;
	int			i;
	int			*prev_tube;
	int			tube[2];
	//int			o;

	c = parse_pipes(read);
	if (!c)
		return (0);
	i = 0;
	prev_tube = easy_alloc(sizeof(int) * 2);
	prev_tube[0] = 0;
	prev_tube[1] = 0;
	while (i != c)
	{
		//printf("!!!!\n");
		printf("%d, %d\n", prev_tube[0], prev_tube[1]);
		if (pipe(tube) == -1)
				exit(0);
		g_context->commands[i]->pid = fork();
		if (g_context->commands[i]->pid == -1)
				exit(1);
		if (g_context->commands[i]->pid == 0)
		{
			//printf("!!!%s!!!\n", g_context->commands[i]->cmd_info->cmd_exec);
			if (g_context->commands[i + 1] && g_context->commands[i + 1]->from_type == FROM_FD)
			{
				g_context->commands[i]->fd[1] = tube[1];
			}
			if (i != 0 && g_context->commands[i - 1]->to_type == TO_FD && g_context->commands[i]->from_type == FROM_FD)
			{
				g_context->commands[i]->fd[0] = prev_tube[0];
			}
			//printf("fd[0] - %d\n", g_context->commands[i]->fd[0]);
			//printf("fd[1] - %d\n", g_context->commands[i]->fd[1]);
			if (g_context->commands[i]->fd[0] != 0)
			{
				dup2(g_context->commands[i]->fd[0], 0);
				//close(g_context->commands[i]->fd[0]);
			}
			if (g_context->commands[i]->fd[1] != 1)
			{
				//o = dup(1);
				dup2(g_context->commands[i]->fd[1], 1);
				//close(g_context->commands[i]->fd[1]);
			}
			if (g_context->commands[i]->cmd_info->is_err)
			{
				parse_errors(4, g_context->commands[i]->cmd_info);
				exit(1);
			}
			//ft_putstr_fd(ft_itoa(tube[0]), o);
			//ft_putstr_fd(ft_itoa(tube[1]), o);
			execve(g_context->commands[i]->cmd_info->cmd_path, g_context->commands[i]->cmd_info->fullcmd, g_context->path);
			
		}
		waitpid(g_context->commands[i]->pid, &g_context->last_exit_code, 0);
		prev_tube[0] = tube[0];
		prev_tube[1] = tube[1];
		if (g_context->commands[i]->pid == 0)
			exit(g_context->last_exit_code);
		++i;
	}
	return (0);
}
