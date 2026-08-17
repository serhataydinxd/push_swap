/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 07:30:03 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/17 11:52:16 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_r_s(t_node **b, size_t i, int is_rrb)
{
	if (is_rrb)
	{
		while (i-- > 0)
			rrb(b);
	}
	else
	{
		while (i-- > 0)
			rb(b);
	}
}

void	index(t_node **a, t_node **b)
{
	t_node	*temp;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	temp = *b;
	while (temp)
	{
		temp = temp->next;
		j++;
	}
	temp = *b;
	while (temp && (*a)->data < temp->data)
	{
		temp = temp->next;
		i++;
	}
	if (i > (j / 2))
	{
		i = j - i;
		make_r_s(b, i, 1);
	}
	else
		make_r_s(b, i, 0);
}

void	insertion_sort(t_node **a)
{
	t_node	*b;

	b = NULL;
	pb(a, &b);
	while (*a)
	{
		if ((*a)->data > b->data)
			pb(a, &b);
		else
		{
			(a, &b);
		}
	}
}
