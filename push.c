/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 06:06:17 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/20 16:41:33 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b, t_counter *t)
{
	t_node	*new;

	if (!(*b))
		return ;
	new = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	new->next = *a;
	new->prev = NULL;
	if (*a)
		(*a)->prev = new;
	*a = new;
	if (t)
	{
		t->c_pa++;
		t->c_total++;
		ft_printf(1, "pa\n");
	}
}

void	pb(t_node **a, t_node **b, t_counter *t)
{
	t_node	*new;

	if (!(*a))
		return ;
	new = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	new->next = *b;
	new->prev = NULL;
	if (*b)
		(*b)->prev = new;
	*b = new;
	if (t)
	{
		t->c_pb++;
		t->c_total++;
		ft_printf(1, "pb\n");
	}
}
