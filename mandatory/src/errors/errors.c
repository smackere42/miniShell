/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:29:03 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:17:52 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	pexit(char *str, char *cause, int flag)
{
	ft_putstr_fd(ERROR_PROMPT, 2);
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	if (cause)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(cause, 2);
	}
	ft_putstr_fd("\033[0m\n", 2);
	g_con->last_exit_code = flag;
	exit(flag);
}

void	allocation_error(int i)
{
	if (i == 1)
	{
		easy_fall();
		write(2, "easy_alloc error\n", 17);
		exit(0);
	}
	if (i == 2)
	{
		easy_fall();
		write(2, "add_p alloc error\n", 19);
		exit(0);
	}
}
