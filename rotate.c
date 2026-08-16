/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:05:56 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/16 16:26:38 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_node **node)
{
	t_node	*temp;
	t_node	*last;

	if (!node || !(*node) || !(*node)->next)
		return ;
	temp = *node;
	last = ft_lstlast(*node);
	*node = temp->next;
	(*node)->prev = 0;
	temp->prev = last;
	last->next = temp;
	temp->next = 0;
}

void	ra(t_node **a)
{
	ft_rotate(a);
}

void	rb(t_node **b)
{
	ft_rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
