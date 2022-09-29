/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:49 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/29 00:07:00 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include "../../../libft/include/libft.h"
# include "../../src/easy_memory/easy_memory.h"
# include "../main/main.h"

typedef struct s_command
{
	char	*fixed_cmd;
	char	*cmd_exec;
	char	**fullcmd;
	char	*cmd_path;
}			t_command;

t_command	*parse(char *cmd);
t_command	*parse_errors(int i, t_command *command);
int			var_iteration(int flag, char *command);
int			check_repeat(char **variable);
char		*replace_one(char *postfix, char *res);
char		*get_postfix(char **left);
char		**get_path(char **envp);

#endif