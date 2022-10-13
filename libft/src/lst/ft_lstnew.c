/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:58:37 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 22:53:03 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *) malloc(sizeof(t_list));
	if (tmp == ((void *)0))
		return ((void *)0);
	tmp->content = content;
	tmp->next = ((void *)0);
	return (tmp);
}
