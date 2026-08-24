/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_selection_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 00:52:47 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/24 09:36:18 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min(t_node **b, size_t *i)
{
	int		min;
	t_node	*temp;

	temp = *b;
	min = (*b)->index;
	while (temp)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	temp = *b;
	while (temp->index != min)
	{
		(*i)++;
		temp = temp->next;
	}
}

void	fake_selection_sort(t_node **a, t_node **b, t_counter *t)
{
	size_t	i;
	size_t	len_b;

	while (*b)
	{
		i = 0;
		len_b = ft_lstsize(*b);
		find_min(b, &i);
		if (i > (len_b / 2))
		{
			i = len_b - i;
			while (i-- > 0)
				rrb(b, t);
		}
		else
		{
			while (i-- > 0)
				rb(b, t);
		}
		pa(a, b, t);
		ra(a, t);
	}
}
