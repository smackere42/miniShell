/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:21:46 by smackere          #+#    #+#             */
/*   Updated: 2022/10/11 17:09:16 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void *parse_errors(int i, t_cmd_info *command)
{
	char	*errors[5];
	char	*tmp;
	//char	*buff;

	tmp = command->cmd_exec + 1;
	errors[0] = "\033[3;31m no memmory allocated for command\n \033[0m";
	errors[1] = "\033[31m no memory allocated for parsing\n \033[0m";
	errors[2] = "\033[31m no memmory allocated for paths\n \033[0m";
	errors[3] = "\033[31m no memmory allocated for cmd\n \033[0m";
	errors[4] = "\033[31m minishell: command not found: \033[0m";
	g_context->last_exit_code = 127;
	ft_putstr_fd(errors[i], 2);
	if (i == 4)
	{
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd("\n", 2);
	}
	f_cmd_info(command);
	return (NULL);
}
