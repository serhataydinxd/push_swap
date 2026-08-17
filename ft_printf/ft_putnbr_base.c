/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:03:43 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/17 16:16:42 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int fd, unsigned int n, char *base)
{
	char	mod;
	int		written;
	int		ret;

	ret = 0;
	if (n >= 16)
	{
		written = ft_putnbr_base(fd, n / 16, base);
		if (written == -1)
			return (-1);
		ret += written;
	}
	mod = base[n % 16];
	written = ft_putchar(fd, mod);
	if (written == -1)
		return (-1);
	ret += written;
	return (ret);
}
