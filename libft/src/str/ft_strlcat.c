/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:57:28 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/13 18:55:56 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(dst + i) && i < dstsize)
		i++;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		i++;
		src++;
	}
	if (i < dstsize)
		*(dst + i) = '\0';
	return (i + ft_strlen(src));
}
