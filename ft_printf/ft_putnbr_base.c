/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:03:43 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/14 12:37:18 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, char *base)
{
	char	mod;
	int		written;
	int		ret;

	ret = 0;
	if (n >= 16)
	{
		written = ft_putnbr_base(n / 16, base);
		if (written == -1)
			return (-1);
		ret += written;
	}
	mod = base[n % 16];
	written = ft_putchar(mod);
	if (written == -1)
		return (-1);
	ret += written;
	return (ret);
}
