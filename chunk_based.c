/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 02:47:31 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/23 17:46:53 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_iteration_count(t_node **a)
{
	int	i;
	int	len_a;

	len_a = ft_lstsize(*a);
	i = 0;
	while (1)
	{
		if (i * i >= len_a * 7)
			return (i);
		i++;
	}
}

static void	build_sorted_array(t_node *a, int *sorted_array, int total_numbers)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (a && i < total_numbers)
	{
		sorted_array[i] = a->data;
		a = a->next;
		i++;
	}
	i = 1;
	while (i < total_numbers)
	{
		j = i;
		while (j > 0 && sorted_array[j - 1] > sorted_array[j])
		{
			temp = sorted_array[j - 1];
			sorted_array[j - 1] = sorted_array[j];
			sorted_array[j] = temp;
			j--;
		}
		i++;
	}
}

static void	push_range(t_node **a, t_node **b, t_chunk *chunk, t_counter *t)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	while (len_a)
	{
		if ((*a)->data >= chunk->chunk_min && (*a)->data <= chunk->chunk_max)
			pb(a, b, t);
		else
			ra(a, t);
		len_a--;
	}
}

static void	sort_chunks(t_node **a, t_node **b, t_chunk *chunk, t_counter *t)
{
	int	i;

	i = 0;
	while (i < chunk->total_numbers)
	{
		chunk->chunk_min = chunk->sorted_array[i];
		if (i + chunk->numbers_per_chunk - 1 >= chunk->total_numbers)
			chunk->chunk_max = chunk->sorted_array[chunk->total_numbers - 1];
		else
			chunk->chunk_max = chunk->sorted_array[i + chunk->numbers_per_chunk
				- 1];
		push_range(a, b, chunk, t);
		fake_selection_sort(a, b, t);
		i += chunk->numbers_per_chunk;
	}
}

void	chunk_based(t_node **a, t_counter *t)
{
	t_node	*b;
	t_chunk	chunk;

	if (is_sorted(*a))
		return ;
	chunk.total_numbers = ft_lstsize(*a);
	chunk.numbers_per_chunk = calculate_iteration_count(a);
	chunk.sorted_array = malloc(sizeof(int) * chunk.total_numbers);
	if (!chunk.sorted_array)
		return ;
	build_sorted_array(*a, chunk.sorted_array, chunk.total_numbers);
	b = NULL;
	sort_chunks(a, &b, &chunk, t);
	free(chunk.sorted_array);
}
