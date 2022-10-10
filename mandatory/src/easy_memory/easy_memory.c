/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:14:07 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/07 01:59:45 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easy_memory.h"

void	easy_fall(void)
{
	t_pointers	*temp;

	while (g_context->pointers)
	{
		temp = g_context->pointers->next;
		if (g_context->pointers->pointer)
			free(g_context->pointers->pointer);
		free(g_context->pointers);
		g_context->pointers = temp;
	}
}

void	allocation_error(int i)
{
	if (i == 1)
	{
		easy_fall();
		write(2, "easy_alloc error\n", 17);
		exit(0);
	}
	if (i == 2)
	{
		easy_fall();
		write(2, "add_p alloc error\n", 19);
		exit(0);
	}
}

void	*easy_alloc(size_t size)
{
	void		*ret;
	t_pointers	*temp;
	
	ret = (void *) malloc(size);
	if (!ret)
		allocation_error(1);
	temp = (t_pointers *) malloc(sizeof(t_pointers));
	if (!temp)
		allocation_error(1);
	temp->pointer = ret;
	if (g_context->pointers == NULL)
		temp->next = NULL;
	else
		temp->next = g_context->pointers;
	g_context->pointers = temp;
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
	if (!g_context->pointers)
		temp->next = NULL;
	else
		temp->next = g_context->pointers;
	temp->pointer = ptr;
	g_context->pointers = temp;
	
	return (ptr);
}

void	f_one(void *ptr)
{
	t_pointers	*temp;
	t_pointers	*previous;
	
	previous = g_context->pointers;
	temp = g_context->pointers;
	while (temp && temp->pointer != ptr)
	{
		previous = temp;
		temp = temp->next;
	}
	if (temp && temp->pointer == ptr)
	{
		free(temp->pointer);
		if (g_context->pointers == temp)
			g_context->pointers = temp->next;
		else
			previous->next = temp->next;
		free(temp);
	}
}

void	f_split(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	f_one(ptr);
}