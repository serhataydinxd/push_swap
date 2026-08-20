/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:02:44 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/20 16:43:55 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rrotate(t_node **node)
{
	t_node	*temp;
	t_node	*last;

	if (!node || !(*node) || !(*node)->next)
		return ;
	last = ft_lstlast(*node);
	temp = last->prev;
	(*node)->prev = last;
	last->next = *node;
	last->prev = 0;
	temp->next = 0;
	*node = last;
}

void	rra(t_node **a, t_counter *t)
{
	ft_rrotate(a);
	if (t)
	{
		t->c_rra++;
		t->c_total++;
		ft_printf(1, "rra\n");
	}
}

void	rrb(t_node **b, t_counter *t)
{
	ft_rrotate(b);
	if (t)
	{
		t->c_rrb++;
		t->c_total++;
		ft_printf(1, "rrb\n");
	}
}

void	rrr(t_node **a, t_node **b, t_counter *t)
{
	ft_rrotate(a);
	ft_rrotate(b);
	if (t)
	{
		t->c_rrr++;
		t->c_total++;
		ft_printf(1, "rrr\n");
	}
}
