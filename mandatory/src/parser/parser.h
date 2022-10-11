/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:49 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 17:09:30 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include "../../../libft/include/libft.h"
# include "../../src/easy_memory/easy_memory.h"
# include "../main/main.h"
# include "../pipex/pipex.h"

typedef struct s_cmd_info
{
	char	*fixed_cmd;
	char	*cmd_exec;
	char	**fullcmd;
	char	*cmd_path;
	int		is_err;
}			t_cmd_info;

t_cmd_info	*parse(char *cmd);
void		*parse_errors(int i, t_cmd_info *command);
int			var_iteration(int flag, char *command);
int			check_repeat(char **variable);
char		*replace_one(char *postfix, char *res);
char		*get_postfix(char **left);
char		**get_path(char **envp);
void		f_cmd_info(t_cmd_info *command);
int			parse_pipes(char *read);

#endif