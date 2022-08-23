/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:42:45 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/11 18:20:42 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;
	size_t			i;

	tmp_s = (unsigned char *)b;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < len)
		*(tmp_s + i++) = tmp_c;
	return (b);
}
