/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/29 00:07:49 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	exec_command(char *read)
{
	int			pid;
	t_command	*cmd;

	cmd = parse(read);
	if (cmd == NULL)
		return (0);
	pid = fork();
	g_context->pid = pid;
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		execve(cmd->cmd_path, cmd->fullcmd, NULL);
	}
	waitpid(pid, &(g_context->last_exit_code), 0);
	f_one(cmd->cmd_path);
	f_one(cmd->fixed_cmd);
	f_one(cmd->fullcmd);
	f_one(cmd->cmd_exec);
	f_one(cmd);
	return (0);
}
