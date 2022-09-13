/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:23:07 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/12 00:10:07 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define PROMPT "\033[1;32m➜ \033 \033[1;36mAHAHAC \033[1;33m✗ \033[0m\033[0m"

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../executor/executor.h"
# include "../easy_memory/easy_memory.h"
//# include "../easy_memory/easy_memory.h"

typedef struct	s_context
{
	int pid;
	struct s_pointers	*pointers;
	struct t_list	*variables;
} t_context;

extern t_context *g_context;
t_context *g_context;


#endif