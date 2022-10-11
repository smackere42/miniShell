/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:29:03 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 17:06:33 by kmumm            ###   ########.fr       */
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
	g_context->last_exit_code = flag;
	exit(flag);
}