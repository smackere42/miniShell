/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:21:46 by smackere          #+#    #+#             */
/*   Updated: 2022/09/01 03:32:58 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_command	*parse_errors(int i, t_command *command)
{
	char	*errors[5];
	char	*tmp;
	char	*buff;

	tmp = command->cmd;
	buff = ++tmp;
	errors[0] = "\033[3;31m no memmory allocated for command\n \033[0m";
	errors[1] = "\033[31m no memory allocated for parsing\n \033[0m";
	errors[2] = "\033[31m no memmory allocated for paths\n \033[0m";
	errors[3] = "\033[31m no memmory allocated for cmd\n \033[0m";
	errors[4] = "\033[31m minishell: command not found: \033[0m";
	ft_putstr_fd(errors[i], 2);
	if (i == 4)
	{
		ft_putstr_fd(buff, 2);
		ft_putstr_fd("\n", 2);
	}
	free(command);
	return (NULL);
}