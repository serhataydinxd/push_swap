/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:02:44 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 14:36:23 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rrotate(t_node **node)
{
	t_node	*temp;
	t_node	*last;

	if (!node || !(*node) || !(*node)->next)
		return (0);
	last = ft_lstlast(*node);
	temp = last->prev;
	(*node)->prev = last;
	last->next = *node;
	last->prev = 0;
	temp->next = 0;
	*node = last;
	return (1);
}

void	rra(t_node **a, t_counter *t)
{
	if (t && ft_rrotate(a))
	{
		t->c_rra++;
		t->c_total++;
		ft_printf(1, "rra\n");
	}
}

void	rrb(t_node **b, t_counter *t)
{
	if (t && ft_rrotate(b))
	{
		t->c_rrb++;
		t->c_total++;
		ft_printf(1, "rrb\n");
	}
}

void	rrr(t_node **a, t_node **b, t_counter *t)
{
	int	done_a;
	int	done_b;

	done_a = ft_rrotate(a);
	done_b = ft_rrotate(b);
	if (t && (done_a || done_b))
	{
		t->c_rrr++;
		t->c_total++;
		ft_printf(1, "rrr\n");
	}
}
