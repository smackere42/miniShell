/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:40:16 by kmumm             #+#    #+#             */
/*   Updated: 2022/06/13 19:38:53 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp_n;

	tmp_n = n;
	if (tmp_n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp_n *= -1;
	}
	if (tmp_n >= 10)
		ft_putnbr_fd(tmp_n / 10, fd);
	ft_putchar_fd('0' + tmp_n % 10, fd);
}
