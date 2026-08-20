/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:24:25 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/20 16:44:49 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **node)
{
	t_node	*first;

	first = (*node);
	first->next = (*node)->next->next;
	first->prev = first->next->prev;
	first->next->prev = first;
	first->prev->prev = NULL;
	first->prev->next = first;
	(*node) = first->prev;
}

void	sa(t_node **a, t_counter *t)
{
	swap(a);
	if (t)
	{
		t->c_sa++;
		t->c_total++;
		ft_printf(1, "sa\n");
	}
}

void	sb(t_node **b, t_counter *t)
{
	swap(b);
	if (t)
	{
		t->c_sb++;
		t->c_total++;
		ft_printf(1, "sb\n");
	}
}

void	ss(t_node **a, t_node **b, t_counter *t)
{
	swap(a);
	swap(b);
	if (t)
	{
		t->c_ss++;
		t->c_total++;
		ft_printf(1, "ss\n");
	}
}
