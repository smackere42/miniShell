/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:23:09 by kmumm             #+#    #+#             */
/*   Updated: 2022/08/21 04:15:12 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	emulate_ctrl_c(int sig_num)
{
	(void) sig_num;
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	return (len);
}

int	check_exit_eof(char *read)
{
	if (!read)
	{
		write(2, "exit\n", 5);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read;

	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, emulate_ctrl_c);
	while (1)
	{
		read = readline(PROMPT);
		if (check_exit_eof(read))
			break ;
		if (ft_strlen(read) > 0)
		{
			exec_command(read, envp);
			add_history(read);
		}
		free(read);
	}
	return (0);
}
