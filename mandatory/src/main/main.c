/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:23:09 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 08:40:13 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	emulate_ctrl_c(int sig_num)
{
	(void) sig_num;
	write(STDERR_FILENO, "\n", 2);
	if (g_context->pid == 0)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	check_exit_eof(char *read)
{
	if (!read)
	{
		free(read);
		ft_putstr_fd("\033[1;31mexit\n\033[0m", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read;

	(void)argc;
	(void)argv;
	
	init_context(envp);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, emulate_ctrl_c);
	while (1)
	{
		read = readline(PROMPT);
		add_history(read);
		if (check_exit_eof(read))
			break ;
		if (ft_strlen(read) > 0)
		{
			exec_command(read);
		}
		free(read);
	}
	rl_clear_history();
	easy_fall();
	return (0);
}
