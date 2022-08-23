/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 07:08:13 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/09 23:47:10 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (*tmp_s)
		tmp_s++;
	while (tmp_s >= s)
	{
		if (*tmp_s == c)
			return (tmp_s);
		tmp_s--;
	}
	return ((void *)0);
}
