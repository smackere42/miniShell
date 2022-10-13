/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:14:07 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:13:21 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easy_memory.h"

void	easy_fall(void)
{
	t_pointers	*temp;

	while (g_con->pointers)
	{
		temp = g_con->pointers->next;
		if (g_con->pointers->pointer)
			free(g_con->pointers->pointer);
		free(g_con->pointers);
		g_con->pointers = temp;
	}
}

void	*easy_alloc(size_t size)
{
	void		*ret;
	t_pointers	*temp;

	ret = (void *) malloc(size);
	if (!ret)
		allocation_error(1);
	temp = (t_pointers *) malloc(sizeof(t_pointers *));
	if (!temp)
		allocation_error(1);
	temp->pointer = ret;
	if (g_con->pointers == NULL)
		temp->next = NULL;
	else
		temp->next = g_con->pointers;
	g_con->pointers = temp;
	return (ret);
}

void	*add_p(void *ptr)
{
	t_pointers	*temp;

	if (!ptr)
		allocation_error(2);
	temp = (t_pointers *) malloc(sizeof(t_pointers));
	if (!temp)
		allocation_error(2);
	if (!g_con->pointers)
		temp->next = NULL;
	else
		temp->next = g_con->pointers;
	temp->pointer = ptr;
	g_con->pointers = temp;
	return (ptr);
}

void	f_one(void *ptr)
{
	t_pointers	*temp;
	t_pointers	*previous;

	previous = g_con->pointers;
	temp = g_con->pointers;
	while (temp && temp->pointer != ptr)
	{
		previous = temp;
		temp = temp->next;
	}
	if (temp && temp->pointer == ptr)
	{
		free(temp->pointer);
		if (g_con->pointers == temp)
			g_con->pointers = temp->next;
		else
			previous->next = temp->next;
		free(temp);
	}
}

void	f_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	f_one(ptr);
}
