/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 06:06:44 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/22 11:29:04 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		result;
	int		has_digit;

	result = 0;
	i = 0;
	sign = 1;
	has_digit = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && check_max_min(result, nptr[i],
			sign))
	{
		has_digit = 1;
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if ((!(nptr[i] >= '0' && nptr[i] <= '9') && nptr[i]) || !has_digit)
		throw_error();
	return (result * sign);
}
