/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 06:06:44 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/23 19:03:01 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sign(const char *nptr, size_t *i, int *sign)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			(*sign) *= -1;
		(*i)++;
	}
}

long	ft_atol(const char *nptr)
{
	size_t	i;
	int		sign;
	long	result;
	int		has_digit;

	result = 0;
	i = 0;
	sign = 1;
	has_digit = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	check_sign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (!check_max_min(result, nptr[i], sign))
			return (2147483648);
		has_digit = 1;
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] || !has_digit)
		return (2147483648);
	return (result * sign);
}
