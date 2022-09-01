/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:50:49 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/01 23:33:29 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include "../../../libft/include/libft.h"

typedef struct s_command
{
	char	**fullcmd;
	char	*cmd;
	char	**args;
	char	*cmd_path;
}			t_command;

t_command	*parse(char *cmd, char **envp);
t_command	*parse_errors(int i, t_command *command);

#endif