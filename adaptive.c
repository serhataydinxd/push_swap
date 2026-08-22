/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:51:08 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 02:10:29 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_node **a, t_counter *t)
{
	if (!is_sorted(*a))
		ra(a, t);
	if (is_sorted(*a))
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

void	adaptive(unsigned int in_dis, t_node **a, t_counter *t, t_config *c)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (in_dis < 2000 || in_dis == 2 || in_dis == 3)
	{
		c->a_strategy = SIMPLE;
		if (in_dis == 2)
			sort_two(a, t);
		else if (in_dis == 3)
			sort_three(a, t);
		else
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
