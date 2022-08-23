/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:11:16 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/11 15:06:48 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (!(!haystack && len == 0) && *haystack)
	{
		j = 0;
		while (*(needle + j) && i + j < len)
		{
			if (*(needle + j) == *(haystack + j))
				j++;
			else
			{
				j = 0;
				break ;
			}
		}
		if (*(needle + j) == '\0')
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return ((void *)0);
}
