/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:45:08 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:02:26 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../main/main.h"
# include "../parser/parser.h"
# include "../errors/errors.h"

# define FD 0
# define FILE 1

typedef struct s_redir
{
	int		type;
	char	*file;
	int		fd;
}	t_redir;

typedef struct s_command
{
	int					pid;
	int					tube[2];
	struct s_cmd_info	*cmd_info;
	struct s_redir		*from;
	struct s_redir		*to;
}	t_command;

void	redir(t_command *cmd);

#endif
