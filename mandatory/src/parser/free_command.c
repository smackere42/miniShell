/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:49:46 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/29 21:55:32 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    free_command(t_command *command)
{
    int j;

    f_one(command->cmd_exec);
	f_one(command->fixed_cmd);
	j = 0;
	while (command->fullcmd[j])
		free(command->fullcmd[j++]);
	f_one(command->fullcmd);
	f_one(command->cmd_path);
	f_one(command);
}