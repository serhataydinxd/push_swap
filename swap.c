/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:24:25 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/17 06:06:04 by ugpolat          ###   ########.fr       */
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
}

void	sa(t_node **a)
{
	swap(a);
}

void	sb(t_node **b)
{
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}