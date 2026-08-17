/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:08:35 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/17 16:11:56 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *next, ...);
int	ft_putstr(int fd, char *s);
int	ft_putchar(int fd, char c);
int	ft_putnbr(int fd, int n);
int	ft_putunbr(int fd, unsigned int n);
int	ft_putnbr_base(int fd, unsigned int nb, char *base);
int	ft_putptr(int fd, void *ptr);

#endif 
