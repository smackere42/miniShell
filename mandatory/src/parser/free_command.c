/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cmd_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:49:46 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/07 02:05:40 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	f_cmd_info(t_cmd_info *command)
{
	f_one(command->cmd_exec);
	f_one(command->fixed_cmd);
	f_split(command->fullcmd);
	f_one(command->cmd_path);
	f_one(command);
}
