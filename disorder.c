/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:33:48 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/16 17:40:35 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	calc_disorder(t_node **a)
{
	t_node			*one;
	t_node			*two;
	unsigned int	total_pairs;
	unsigned int	mistakes;

	if (!a || !*a)
		return (0);
	one = *a;
	total_pairs = 0;
	mistakes = 0;
	while (one)
	{
		two = one->next;
		while (two)
		{
			total_pairs++;
			if (one->data > two->data)
				mistakes++;
			two = two->next;
		}
		one = one->next;
	}
	return ((mistakes * 100) / total_pairs);
}
