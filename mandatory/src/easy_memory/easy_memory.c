/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:14:07 by kmumm             #+#    #+#             */
/*   Updated: 2022/09/19 22:47:52 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easy_memory.h"

void	easy_fall(void)
{
	t_pointers 	*temp;
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

void allocation_error(void)
{
	easy_fall();
	write(2, "Error: allocation error", 15);
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
	return ret;
}


void	easy_addp(void *ptr)
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
}

void	easy_fone(void *ptr)
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
	if (temp->pointer == ptr)
	{
		free(temp->pointer);
		previous->next = temp->next;
	}
}