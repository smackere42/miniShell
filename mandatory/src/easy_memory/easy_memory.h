/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:25:53 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/11 23:55:51 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EASY_MEMORY_H
# define FT_EASY_MEMORY_H

# include "../../../libft/include/libft.h"
# include "../main/main.h"
# include <unistd.h>

typedef struct	s_pointers
{
	void				*pointer;
	struct s_pointers	*next;
} t_pointers;

//extern t_pointers *g_pointers;
//t_pointers *g_pointers;

void	*easy_alloc(size_t size);
void	easy_fall(void);
void	easy_fone(void *ptr);
void	easy_addp(void *ptr);



#endif
