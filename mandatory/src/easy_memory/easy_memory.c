/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:14:07 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/23 02:56:02 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easy_memory.h"

void	easy_fall(void)
{
	t_pointers	*temp;
	t_pointers	*pointers;

	pointers = g_context->pointers;
	while (pointers)
	{
		temp = pointers;
		free(pointers->pointer);
		pointers = pointers->next;
		free(temp);
	}
}

void	allocation_error(void)
{
	easy_fall();
	write(2, "Error: allocation error", 24);
	exit(0);
}

void	*easy_alloc(size_t size)
{
	void		*ret;
	t_pointers	*temp;
	t_pointers	*pointers;

	pointers = g_context->pointers;
	ret = (void *) malloc(size);
	if (!ret)
		allocation_error();
	temp = (t_pointers *) malloc(sizeof(t_pointers));
	if (!temp)
		allocation_error();
	if (pointers == NULL)
	{
		pointers = temp;
		pointers->pointer = ret;
		pointers->next = NULL;
	}
	else
	{
		temp->next = pointers;
		temp->pointer = ret;
		pointers = temp;
	}
	return (ret);
}

void	*add_p(void *ptr)
{
	t_pointers	*temp;
	t_pointers	*pointers;

	pointers = g_context->pointers;
	if (!ptr)
		allocation_error();
	temp = (t_pointers *) malloc(sizeof(t_pointers));
	if (!temp)
		allocation_error();
	if (!pointers)
	{
		pointers = temp;
		pointers->pointer = ptr;
		pointers->next = NULL;
	}
	else
	{
		temp->next = pointers;
		temp->pointer = ptr;
		pointers = temp;
	}
	return (ptr);
}

void	f_one(void *ptr)
{
	t_pointers	*temp;
	t_pointers	*previous;
	t_pointers	*pointers;

	pointers = g_context->pointers;
	previous = pointers;
	temp = pointers;
	while (temp && temp->pointer != ptr)
	{
		previous = temp;
		temp = temp->next;
	}
	if (temp && temp->pointer == ptr)
	{
		free(temp->pointer);
		previous->next = temp->next;
		free(temp);
	}
}
