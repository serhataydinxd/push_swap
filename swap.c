/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:24:25 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/22 11:32:51 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **node)
{
	t_node	*first;
	t_node	*second;

	if (!node || !(*node) || !(*node)->next)
		return ;
	first = (*node);
	second = first->next;
	if (!second->next)
	{
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		first->next = NULL;
		*node = second;
		return ;
	}
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	(*node) = second;
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
