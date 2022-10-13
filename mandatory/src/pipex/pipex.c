/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:58:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:03:42 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_close(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(oldfd);
}

void	redir(t_command *cmd)
{
	int	fd;

	if (cmd->from->type == FD)
	{
		if (cmd->from->fd != 0)
			dup2_close(cmd->from->fd, 0);
	}
	else if (cmd->from->type == FILE)
	{
		fd = open(cmd->from->file, O_RDONLY);
		if (fd == -1)
			pexit("No such file or directory", cmd->from->file, 1);
		dup2_close(fd, 0);
	}
	if (cmd->to->type == FD)
	{
		if (cmd->to->fd != 1)
			dup2_close(cmd->to->fd, 1);
	}
	else if (cmd->to->type == FILE)
	{
		fd = open(cmd->to->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			pexit("No such file or directory", cmd->from->file, 1);
		dup2_close(fd, 1);
	}
}
