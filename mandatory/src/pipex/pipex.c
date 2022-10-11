/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:58:23 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 16:41:17 by kmumm            ###   ########.fr       */
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
	if (cmd->from->type == FD)
	{
		if (cmd->from->fd != 0)
			dup2_close(cmd->from->fd, 0);
	}
	else if (cmd->from->type == FILE)
	{
		int fd = open(cmd->from->file, O_RDONLY);
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
		int fd = open(cmd->to->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			pexit("No such file or directory", cmd->from->file, 1);
		dup2_close(fd, 1);
	}
}

//void	set_last_status(t_shell *shell, t_cmd *child, int wstat)
//{
//	if (WIFEXITED(wstat))
//		set_env(shell->env, "?", ft_itoa(WEXITSTATUS(wstat)));
//	else if (WIFSIGNALED(wstat))
//		set_env(shell->env, "?", ft_itoa(WTERMSIG(wstat) + 128));
//	set_env(shell->env, "_", child->cmd_name);
//}

//t_cmd	*who_returned(t_shell *shell, int pid)
//{
//	int	i;

//	i = -1;
//	while (++i < shell->cmds_count)
//	{
//		if (shell->cmds_arr[i]->pid == pid)
//			return (shell->cmds_arr[i]);
//	}
//	return (NULL);
//}

//void	wait_all_children(t_shell *shell)
//{
//	int			i;
//	int			ret;
//	int			wstat;
//	t_cmd		*cmd;

//	i = -1;
//	wstat = 0;
//	while (++i < shell->cmds_count)
//	{
//		ret = waitpid(0, &wstat, 0);
//		cmd = who_returned(shell, ret);
//		set_last_status(shell, cmd, wstat);
//		if (cmd)
//		{
//			if (cmd->fd[0] != 0)
//				close(cmd->fd[0]);
//			if (cmd->fd[1] != 1)
//				close(cmd->fd[1]);
//		}
//	}
//}

//void	pipex(t_shell *shell)
//{
//	if (shell->cmds_count == 1 && is_nofork(shell->cmds_arr[0]->cmd_name))
//	{
//		run_nofork(shell->cmds_arr[0], shell->env);
//		return ;
//	}
//	else
//		run_multi_commands(shell);
//	wait_all_children(shell);
//}


//void	pre_exec_cmd(t_cmd *cmd, t_shell *shell)
//{
//	int	err;

//	signal(SIGQUIT, handler_child_quit);
//	if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
//	{
//		err = errno;
//		close_all(shell);
//		err_exit_txt(M_SH, "dup2", strerror(err), 1);
//	}
//	close_all(shell);
//	if (cmd->cmd_name)
//	{
//		if (is_cmd(cmd->cmd_name))
//			run_cmd(cmd, shell->env);
//		if (!ft_strncmp(cmd->cmd_name, "exit", ft_strlen("exit")))
//			exit (0);
//		exec_cmd(cmd, shell);
//	}
//	else
//		exit(0);
//}

//void	run_multi_commands(t_shell *shell)
//{
//	int	i;

//	i = -1;
//	while (++i < shell->cmds_count)
//	{
//		shell->cmds_arr[i]->pid = fork();
//		if (shell->cmds_arr[i]->pid == -1)
//			perror("minishell: fork");
//		else if (shell->cmds_arr[i]->pid > 0)
//		{
//			signal(SIGINT, sig_int_proc);
//			signal(SIGQUIT, sig_int_proc);
//			shell->pid_c = shell->cmds_arr[i]->pid;
//		}
//		else if (shell->cmds_arr[i]->pid == 0)
//			pre_exec_cmd(shell->cmds_arr[i], shell);
//	}
//}
