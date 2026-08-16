/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:27:56 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/14 14:38:01 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long long p)
{
	char	*base;
	int		ret;
	char	mod;
	int		written;

	ret = 0;
	base = "0123456789abcdef";
	if (p >= 16)
	{
		written = ft_puthex(p / 16);
		if (written == -1)
			return (-1);
		ret += written;
	}
	mod = base[p % 16];
	written = ft_putchar(mod);
	if (written == -1)
		return (-1);
	ret += written;
	return (ret);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	p;
	int					ret;
	int					written;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = 0;
	written = ft_putstr("0x");
	if (written == -1)
		return (-1);
	ret += written;
	p = (unsigned long long)ptr;
	written = ft_puthex(p);
	if (written == -1)
		return (-1);
	ret += written;
	return (ret);
}
