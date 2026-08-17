/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:54:48 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/17 16:21:28 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(int fd, unsigned int n)
{
	char	mod;
	int		ret;
	int		written;

	ret = 0;
	if (n >= 10)
	{
		written = ft_putunbr(fd, n / 10);
		if (written == -1)
			return (-1);
		ret += written;
	}
	mod = (n % 10) + '0';
	written = ft_putchar(fd, mod);
	if (written == -1)
		return (-1);
	ret += written;
	return (ret);
}
