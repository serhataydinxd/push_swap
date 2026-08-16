/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:17:43 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/14 11:23:49 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	a;

	a = 0;
	if (!s)
		s = "(null)";
	while (s[a])
	{
		if (ft_putchar(s[a]) == -1)
			return (-1);
		a++;
	}
	return (a);
}
