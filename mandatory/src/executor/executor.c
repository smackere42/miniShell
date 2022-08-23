/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:16:01 by kmumm             #+#    #+#             */
/*   Updated: 2022/08/21 04:17:14 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	exec_command(char *read, char **envp)
{
	char *cmd;
	int pid;
	int	status;
	
	cmd = get_cmd(read, envp);
	if (cmd == NULL)
		return (0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		execve(cmd, NULL, NULL);
	}
	waitpid(pid, &status, 0);
	return (0);
}