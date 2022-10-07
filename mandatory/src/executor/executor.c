/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/07 06:18:09 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	exec_command(char *read)
{
	int			pid;
	int			c;
	int			i;
	//t_cmd_info	*cmd;

	c = parse_pipes(read);
	if (!c)
		return (0);
	//cmd = parse(read);
	//if (cmd == NULL)
	//	return (0);;
	//if (cmd->is_err)
	//	return (0);
	pid = fork();
	g_context->pid = pid;
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		i = 0;
		while (i != c)
		{
			g_context->commands[i]->pid = fork();
			if (g_context->commands[i]->pid == -1)
					exit(1);
			if (g_context->commands[i]->pid == 0)
			{
				if (g_context->commands[i]->cmd_info->is_err)
				{
					parse_errors(4, g_context->commands[i]->cmd_info);
					g_context->last_exit_code = 1;
					printf("in pid: %d, last_exit_code: %d\n", getpid(), g_context->last_exit_code);
					exit(1);
				}
				execve(g_context->commands[i]->cmd_info->cmd_path, g_context->commands[i]->cmd_info->fullcmd, g_context->path);
				
			}
			waitpid(g_context->commands[i]->pid, &g_context->last_exit_code, 0);
			if (g_context->commands[i]->pid == 0)
				exit(0);
			++i;
		}
		g_context->last_exit_code = 42;
		exit(0);
	}
	//if (g_context->last_cmd_name)
	//	f_one(g_context->last_cmd_name);
	//g_context->last_cmd_name = add_p(ft_strdup(cmd->cmd_exec + 1));
	waitpid(pid, &g_context->last_exit_code, 0);
	printf("last exit code: %d\n", g_context->last_exit_code);
	//free_command(cmd);
	return (0);
}
