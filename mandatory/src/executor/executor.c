/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/12 00:17:40 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	exec_command(char *read, char **envp)
{
	int			pid;
	int			status;
	t_command	*cmd;

	cmd = parse(read, envp);
	if (cmd == NULL)
		return (0);
	pid = fork();
	g_context->pid = pid;
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		execve(cmd->cmd_path, cmd->args, NULL);
	}
	waitpid(pid, &status, 0);
	return (0);
}
