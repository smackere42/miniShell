/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:49:37 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/13 01:19:49 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tmp_c;
	unsigned char	*tmp_s;
	size_t			i;

	tmp_c = (unsigned char)c;
	tmp_s = (unsigned char *)s;
	i = -1;
	while (++i < n)
	{
		if (tmp_c == *tmp_s)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return ((void *)0);
}
