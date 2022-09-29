/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:23:09 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/29 21:56:50 by kmumm            ###   ########.fr       */
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
		free(read);
		ft_putstr_fd("\033[1;31mexit\n\033[0m", 2);
		return (1);
	}
	return (0);
}

void	print_loc_var(void *content)
{
	char	**temp;

	temp = (char **) content;
	ft_putstr_fd(temp[0], 2);
	ft_putstr_fd(" = ", 2);
	ft_putstr_fd(temp[1], 2);
	ft_putstr_fd("\n", 2);
}

int		num_of_pointers()
{
	int i = 0;
	t_pointers *temp;

	temp = (t_pointers *) g_context->pointers;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read;

	(void)argc;
	(void)argv;
	g_context = (t_context *) malloc(sizeof(t_context));
	g_context->pid = 0;
	g_context->last_exit_code = 0;
	g_context->pointers = NULL;
	g_context->variables = NULL;
	g_context->path = get_path(envp);
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
