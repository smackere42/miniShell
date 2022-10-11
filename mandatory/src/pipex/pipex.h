/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:45:08 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 07:36:19 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../main/main.h"
# include "../parser/parser.h"

# define FD 0
# define FILE 1

typedef struct s_redirect
{
	int		type;
	char	*file;
	int		fd;
}	t_redirect;

typedef struct s_command
{
	int					pid;
	struct s_cmd_info	*cmd_info;
	t_redirect			*from;
	t_redirect			*to;
}	t_command;

void	redir(t_command *cmd);

#endif
