/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 02:47:31 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/24 13:17:39 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk_size(t_node **a)
{
	int	i;
	int	len_a;

	len_a = ft_lstsize(*a);
	i = 0;
	while (1)
	{
		if (i * i >= len_a * 5)
			return (i);
		i++;
	}
}

static void	push_range(t_node **a, t_node **b, t_chunk *chunk, t_counter *t)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	while (len_a)
	{
		if ((*a)->index >= chunk->chunk_min && (*a)->index <= chunk->chunk_max)
			pb(a, b, t);
		else
			ra(a, t);
		len_a--;
	}
}

static void	sort_chunks(t_node **a, t_node **b, t_chunk *chunk, t_counter *t)
{
	int	i;

	i = chunk->total_numbers;
	while (i > 0)
	{
		chunk->chunk_max = i - 1;
		chunk->chunk_min = i - chunk->numbers_per_chunk;
		if (chunk->chunk_min < 0)
			chunk->chunk_min = 0;
		push_range(a, b, chunk, t);
		fake_selection_sort(a, b, t);
		i = chunk->chunk_min;
	}
}

void	chunk_based(t_node **a, t_counter *t)
{
	t_node	*b;
	t_chunk	chunk;

	if (is_sorted(*a))
		return ;
	chunk.total_numbers = ft_lstsize(*a);
	chunk.numbers_per_chunk = calculate_chunk_size(a);
	b = NULL;
	sort_chunks(a, &b, &chunk, t);
}
