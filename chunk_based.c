/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 02:47:31 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/20 10:43:47 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_iteration_count(t_node *a)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_lstsize(a);
	while (1)
	{
		if (j * j == i)
			return (j);
		if (j * j > i)
			return ((j - 1));
		j++;
	}
}
void	rotate_and_push(t_node **a, t_node **b, size_t input_range, size_t min,
		size_t i)
{
	size_t	total;
	size_t	counter;
	size_t	temp_counter;
	size_t	total_count;

	total_count = 0;
	total = ft_lstsize(*a) - i;
	counter = 0;
	while (total > total_count)
	{
		if ((*a)->data < (input_range + min) && (*a)->data > min)
		{
			pb(a, b);
			total_count++;
		}
		else
		{
			total_count++;
			ra(a);
			counter++;
		}
	}
	while (counter-- > 0)
		rra(a);
}

void	handle_b(t_node **a, size_t temp, t_node **b, size_t nodes_done)
{
	size_t	min;
	size_t	max;
	size_t	input_range;
	size_t	i;
	t_node	*temp_a;

	temp_a = *a;
	i = temp * nodes_done;
	min = temp_a->data;
	max = temp_a->data;
	while ((ft_lstsize(*a) - i) > 0 && temp_a)
	{
		if (min > temp_a->data)
			min = temp_a->data;
		if (max < temp_a->data)
			max = temp_a->data;
		temp_a = temp_a->next;
		i++;
	}
	input_range = (max - min) / calculate_iteration_count(*a);
	rotate_and_push(a, b, input_range, min, i);
}

void	chunk_based(t_node **a)
{
	t_node *b;
	size_t iteration_count;
	size_t number_of_elements;
	size_t temp;
	b = NULL;
	iteration_count = calculate_iteration_count(*a);
	number_of_elements = ft_lstsize(*a) / iteration_count;
	while (iteration_count)
	{
		handle_b(a, number_of_elements, &b, ((ft_lstsize(*a)
					/ number_of_elements) - iteration_count));
		selection_sort(&b);
		temp = number_of_elements;
		while (temp > 0)
		{
			pa(a, &b);
			ra(a);
			temp--;
		}
		iteration_count--;
	}
}