/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 07:30:03 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/22 10:35:54 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_push(t_node **a, t_node **b, size_t i, t_counter *t)
{
	size_t	temp;

	temp = ft_lstsize(*a);
	if (i <= (temp / 2))
	{
		while (i--)
			ra(a, t);
	}
	else
	{
		i = temp - i;
		while (i--)
			rra(a, t);
	}
	pb(a, b, t);
}

void	selection_sort(t_node **a, t_counter *t)
{
	t_node	*temp;
	t_node	*b;
	size_t	i;
	size_t	j;
	int		min_val;

	if (is_sorted(*a))
		return ;
	b = NULL;
	while (*a)
	{
		temp = *a;
		i = 0;
		j = 1;
		min_val = temp->data;
		while (temp)
		{
			i++;
			if (temp && min_val > temp->data)
			{
				min_val = temp->data;
				j = i;
			}
			temp = temp->next;
		}
		rotate_push(a, &b, j - 1, t);
	}
	while (b)
		pa(a, &b, t);
}
