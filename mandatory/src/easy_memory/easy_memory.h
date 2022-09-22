/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:25:53 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/22 04:17:01 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_MEMORY_H
# define EASY_MEMORY_H

# include "../../../libft/include/libft.h"
# include "../main/main.h"
# include <unistd.h>

typedef struct s_pointers
{
	void				*pointer;
	struct s_pointers	*next;
}	t_pointers;

extern t_pointers	*g_pointers;
t_pointers	*g_pointers;

void	*easy_alloc(size_t size);
void	easy_fall(void);
void	easy_fone(void *ptr);
void	*easy_addp(void *ptr);

#endif
