/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:15:18 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/10 02:47:26 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*next;

	if (!lst)
		return ((void *)0);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return ((void *)0);
	next = new;
	tmp = lst->next;
	while (tmp)
	{
		next->next = ft_lstnew((*f)(tmp->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return ((void *)0);
		}
		next = next->next;
		tmp = tmp->next;
	}
	return (new);
}
