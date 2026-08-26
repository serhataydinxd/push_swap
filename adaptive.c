/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:51:08 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/26 11:13:56 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_node **a, t_counter *t)
{
	if (!is_sorted(*a))
		ra(a, t);
	return ;
}

static void	sort_three(t_node **a, t_counter *t)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (is_sorted(*a))
		return ;
	if (first < third && third < second)
	{
		rra(a, t);
		sa(a, t);
	}
	else if (second < first && first < third)
		sa(a, t);
	else if (third < first && first < second)
		rra(a, t);
	else if (second < third && third < first)
		ra(a, t);
	else
	{
		sa(a, t);
		rra(a, t);
	}
}

static void	sort_four_five(t_node **a, t_counter *t, int size)
{
	t_node	*b;
	size_t	j;

	if (is_sorted(*a))
		return ;
	b = NULL;
	j = 1;
	while (size-- > 3)
	{
		find_min(a, &j);
		rotate_push(a, &b, (j - 1), t);
	}
	sort_three(a, t);
	while (b)
		pa(a, &b, t);
}

static void	sort_shorts(int size, t_node **a, t_counter *t, t_config *c)
{
	c->a_strategy = SIMPLE;
	if (size == 2)
		sort_two(a, t);
	else if (size == 3)
		sort_three(a, t);
	else
		sort_four_five(a, t, size);
}

void	adaptive(unsigned int in_dis, t_node **a, t_counter *t, t_config *c)
{
	int	size;

	if (!a || !*a || !(*a)->next)
	{
		c->a_strategy = SIMPLE;
		return ;
	}
	size = ft_lstsize(*a);
	if (size >= 2 && size <= 5)
		sort_shorts(size, a, t, c);
	else if (in_dis < 2000)
	{
		c->a_strategy = SIMPLE;
		selection_sort(a, t);
	}
	else if (in_dis < 5000)
	{
		c->a_strategy = MEDIUM;
		chunk_based(a, t);
	}
	else
	{
		c->a_strategy = COMPLEX;
		radix_sort(a, t);
	}
}
