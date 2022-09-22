/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:49 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/22 04:14:21 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include "../../../libft/include/libft.h"
# include "../../src/easy_memory/easy_memory.h"

typedef struct s_command
{
	char	**fullcmd;
	char	*cmd;
	char	**args;
	char	*cmd_path;
}			t_command;

t_command	*parse(char *cmd, char **envp);
t_command	*parse_errors(int i, t_command *command);
int			var_iteration(int flag, char *command);
t_list		*list_iteration(t_list *temp, int i, int j, char **variable);
char		*var_replace_counter(t_list *var, char *r, char *tmp, char *res);
char		*string_move(char *right);

#endif