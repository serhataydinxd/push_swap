/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 02:47:31 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/21 00:14:01 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_iteration_count(t_node **a)
{
	size_t	i;
	size_t	len_a;

	len_a = ft_lstsize(*a);
	i = 0;
	while (1)
	{
		if (i * i >= len_a)
			return (i);
		i++;
	}
}

void	rotate_and_push(t_node **a, t_node **b, size_t end_limit, size_t min,
		t_counter *t)
{
	size_t	count;
	size_t	a_len;

	a_len = ft_lstsize(*a);
	count = 0;
	while (a_len)
	{
		if ((*a)->data <= end_limit && (*a)->data >= min)
		{
			pb(a, b, t);
			count++;
		}
		else
		{
			ra(a, t);
		}
		a_len--;
	}
	selection_sort(b, t);
	while (count--)
	{
		pa(a, b, t);
		ra(a, t);
	}
}

void	handle_b(t_node **a, t_node **b, size_t iteration_count_left,
		t_counter *t)
{
	t_node	*temp;
	size_t	min;
	size_t	max;
	size_t	end_limit;
	size_t	temp_num;

	temp_num = (iteration_count_left) * (ft_lstsize(*a)
			/ calculate_iteration_count(a));
	temp = *a;
	min = temp->data;
	max = temp->data;
	while (temp && temp_num)
	{
		if (temp->data > max)
			max = temp->data;
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
		temp_num--;
	}
	end_limit = min + (max - min) / iteration_count_left;
	rotate_and_push(a, b, end_limit, min, t);
}

void	chunk_based(t_node **a, t_counter *t)
{
	t_node *b;
	size_t iteration_count;
	size_t iteration_count_left;
	size_t i;
	i = 0;
	b = NULL;
	iteration_count = calculate_iteration_count(a);
	while (iteration_count)
	{
		iteration_count_left = calculate_iteration_count(a) - i;
		handle_b(a, &b, iteration_count_left, t);
		i++;
		iteration_count--;
	}
}