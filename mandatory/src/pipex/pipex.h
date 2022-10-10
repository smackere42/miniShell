/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:45:08 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 00:25:00 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../main/main.h"
# include "../parser/parser.h"

# define FROM_DOC 1
# define FROM_FD 2
# define TO_DOC 1
# define TO_FD 2

typedef struct s_command
{
	int					pid;
	struct s_cmd_info	*cmd_info;
	int					fd[2];
	int					from_type;
	int					to_type;
}	t_command;
#endif
