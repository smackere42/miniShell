/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:25:53 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/23 02:56:02 by kmumm            ###   ########.fr       */
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

void	*easy_alloc(size_t size);
void	easy_fall(void);
void	f_one(void *ptr);
void	*add_p(void *ptr);

#endif
