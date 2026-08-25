/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 06:06:44 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/25 12:22:11 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static void	handle_digit(const char *str, size_t *b, int *sign)
{
	if (str[*b] == '-' || str[*b] == '+')
	{
		if (str[*b] == '-')
			*sign = -1;
		(*b)++;
	}
}

int	ft_atol(const char *str, size_t *b, int *value)
{
	long	result;
	int		sign;
	int		has_digit;

	result = 0;
	sign = 1;
	has_digit = 0;
	while (is_space(str[*b]))
		(*b)++;
	if (!str[*b])
		return (0);
	handle_digit(str, b, &sign);
	while (str[*b] >= '0' && str[*b] <= '9')
	{
		if (!check_max_min(result, str[*b], sign))
			return (-1);
		result = result * 10 + (str[*b] - '0');
		has_digit = 1;
		(*b)++;
	}
	if (!has_digit || (str[*b] && !is_space(str[*b])))
		return (-1);
	*value = (int)(result * sign);
	return (1);
}
