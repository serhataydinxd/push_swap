/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:05:43 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/17 16:24:39 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(int fd, const char c, va_list *tracker)
{
	if (c == 'c')
		return (ft_putchar(fd, (char)va_arg(*tracker, int)));
	else if (c == 's')
		return (ft_putstr(fd, va_arg(*tracker, char *)));
	else if (c == 'p')
		return (ft_putptr(fd, va_arg(*tracker, void *)));
	else if (c == 'd')
		return (ft_putnbr(fd, va_arg(*tracker, int)));
	else if (c == 'i')
		return (ft_putnbr(fd, va_arg(*tracker, int)));
	else if (c == 'u')
		return (ft_putunbr(fd, va_arg(*tracker, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(fd, va_arg(*tracker, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(fd, va_arg(*tracker, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar(fd, '%'));
	return (0);
}

static int	handle_next(int fd, const char *next, va_list *tracker)
{
	int	a;
	int	written;
	int	counter;

	a = 0;
	counter = 0;
	while (next[a])
	{
		if (next[a] == '%')
		{
			if (next[a + 1] != '\0')
				written = handle_format(fd, next[++a], tracker);
			else
				return (-1);
		}
		else
			written = ft_putchar(fd, next[a]);
		if (written == -1)
			return (-1);
		counter += written;
		a++;
	}
	return (counter);
}

int	ft_printf(int fd, const char *next, ...)
{
	int		counter;
	va_list	tracker;

	va_start(tracker, next);
	counter = handle_next(fd, next, &tracker);
	va_end(tracker);
	return (counter);
}
