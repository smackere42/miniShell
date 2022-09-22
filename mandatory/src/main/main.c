/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:23:09 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/23 01:52:28 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	emulate_ctrl_c(int sig_num)
{
	(void) sig_num;
	write(STDERR_FILENO, "\n", 2);
	printf("%d\n", g_context->pid);
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

int	main(int argc, char **argv, char **envp)
{
	char	*read;

	(void)argc;
	(void)argv;
	// for(int i = 0; envp[i]; i++)
	// {
	// 	printf("%s\n", envp[i]);
	// }
	g_context = (t_context *) malloc(sizeof(t_context));
	g_context->pid = 0;
	g_context->pointers = NULL;
	g_context->variables = NULL;
	signal(SIGQUIT, SIG_IGN);
	printf("%d\n", g_context->pid);
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
		//ft_lstiter((t_list *)g_context->variables,print_loc_var);
		free(read);
	}
	return (0);
}
