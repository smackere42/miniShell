/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:23:07 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 17:02:42 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define PROMPT "\033[1;32m➜ \033 \033[1;36mAHAHAC \033[1;33m✗ \033[0m\033[0m"
# define ERROR_PROMPT "\033[1;31m➜ AHAHAC 🚫 \033[0m"

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../executor/executor.h"
# include "../easy_memory/easy_memory.h"
# include "../pipex/pipex.h"
# include "../context/context.h"
# include "../../../libft/include/libft.h"

typedef struct s_context
{
	int					pid;
	char				**envp;
	struct s_pointers	*pointers;
	struct t_list		*variables;
	int					last_exit_code;
	char				*last_cmd_name;
	char				**path;
	struct s_command	**commands;
}	t_context;

extern t_context	*g_context;
t_context			*g_context;

#endif