/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:24:25 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/23 14:37:10 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_node **node)
{
	t_node	*first;
	t_node	*second;

	if (!node || !(*node) || !(*node)->next)
		return (0);
	first = (*node);
	second = first->next;
	if (!second->next)
	{
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		first->next = NULL;
		*node = second;
		return (1);
	}
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	(*node) = second;
	return (1);
}

void	sa(t_node **a, t_counter *t)
{
	if (t && swap(a))
	{
		t->c_sa++;
		t->c_total++;
		ft_printf(1, "sa\n");
	}
}

void	sb(t_node **b, t_counter *t)
{
	if (t && swap(b))
	{
		t->c_sb++;
		t->c_total++;
		ft_printf(1, "sb\n");
	}
}

void	ss(t_node **a, t_node **b, t_counter *t)
{
	int	done_a;
	int	done_b;

	done_a = swap(a);
	done_b = swap(b);
	if (t && (done_a || done_b))
	{
		t->c_ss++;
		t->c_total++;
		ft_printf(1, "ss\n");
	}
}
