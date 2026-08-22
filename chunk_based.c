/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 02:47:31 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/22 10:36:19 by ugpolat          ###   ########.fr       */
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

size_t	rotate_and_push(t_node **a, t_node **b, int end_limit, int min,
		t_counter *t)
{
	size_t	count;
	size_t	a_len;
	size_t	processed_num_count;

	processed_num_count = 0;
	a_len = ft_lstsize(*a);
	count = 0;
	while (a_len)
	{
		if ((int)(*a)->data <= end_limit && (int)(*a)->data >= min)
		{
			pb(a, b, t);
			count++;
			processed_num_count++;
		}
		else
			ra(a, t);
		a_len--;
	}
	selection_sort(b, t);
	while (count)
	{
		pa(a, b, t);
		ra(a, t);
		count--;
	}
	return (processed_num_count);
}

size_t	handle_b(t_node **a, t_node **b, size_t unprocessed_num,
		size_t iteration_count_left, t_counter *t)
{
	t_node	*temp;
	int		min;
	int		max;
	int		end_limit;

	temp = *a;
	min = temp->data;
	max = temp->data;
	while (temp && unprocessed_num)
	{
		if ((int)temp->data > max)
			max = temp->data;
		if ((int)temp->data < min)
			min = temp->data;
		temp = temp->next;
		unprocessed_num--;
	}
	end_limit = min + (max - min) / iteration_count_left;
	return (rotate_and_push(a, b, end_limit, min, t));
}

void	chunk_based(t_node **a, t_counter *t)
{
	t_node	*b;
	size_t	iteration_count;
	size_t	i;
	size_t	unprocessed_num_count;
	size_t	iteration_count_left;

	i = 0;
	unprocessed_num_count = ft_lstsize(*a);
	b = NULL;
	iteration_count = calculate_iteration_count(a);
	while (iteration_count)
	{
		iteration_count_left = calculate_iteration_count(a) - i;
		unprocessed_num_count = unprocessed_num_count - handle_b(a, &b,
				unprocessed_num_count, iteration_count_left, t);
		i++;
		iteration_count--;
	}
}
