/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 12:17:34 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 20:05:33 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_size(t_node *a)
{
	int	max;
	int	bit;

	if (!a)
		return (0);
	max = 0;
	bit = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while (max != 0)
	{
		max >>= 1;
		bit++;
	}
	return (bit);
}

static void	sorter(t_node **a, t_node **b, t_counter *t)
{
	int		max_bit;
	int		bit;
	int		size;
	int		i;

	max_bit = bit_size(*a);
	size = ft_lstsize(*a);
	bit = 0;
	while (max_bit > bit)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index >> bit) & 1) == 1)
				ra(a, t);
			else
				pb(a, b, t);
			i++;
		}
		while (*b)
			pa(a, b, t);
		bit++;
	}
}

void	radix_sort(t_node **a, t_counter *t)
{
	t_node	*b;

	if (!a || !*a || !(*a)->next || is_sorted(*a))
		return ;
	b = 0;
	sorter(a, &b, t);
}
