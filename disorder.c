/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:33:48 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/22 10:38:05 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	calc_disorder(t_node **a)
{
	t_node			*one;
	t_node			*two;
	int				total_pairs;
	int				mistakes;
	unsigned int	scaled;

	if (!a || !*a || !(*a)->next)
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
	scaled = (mistakes * 10000) / total_pairs;
	return (scaled);
}
