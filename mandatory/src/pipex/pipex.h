/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:45:08 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/07 02:52:57 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../main/main.h"
# include "../parser/parser.h"

typedef struct s_command
{
	int					pid;
	struct s_cmd_info	*cmd_info;
	int					fd[2];
	
}	t_command;
#endif
