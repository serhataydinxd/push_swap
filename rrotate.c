/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:02:44 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/16 16:26:43 by seraydin         ###   ########.fr       */
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

void	rra(t_node **a)
{
	ft_rrotate(a);
}

void	rrb(t_node **b)
{
	ft_rrotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
}
