/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:42:57 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/14 14:34:36 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	nb;
	int			ret;
	int			written;

	ret = 0;
	nb = n;
	if (nb < 0)
	{
		ret = ft_putchar('-');
		nb = -nb;
		if (ret == -1)
			return (-1);
	}
	if (nb >= 10)
	{
		written = ft_putnbr(nb / 10);
		if (written == -1)
			return (-1);
		ret += written;
	}
	written = ft_putchar((nb % 10) + '0');
	if (written == -1)
		return (-1);
	return (ret + written);
}
