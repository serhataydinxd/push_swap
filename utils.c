/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:48:36 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/20 16:45:56 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *stk)
{
	if (!stk)
		return (0);
	while (stk->next != 0)
	{
		stk = stk->next;
	}
	return (stk);
}

unsigned int	ft_lstsize(t_node *stk)
{
	unsigned int	size;

	size = 0;
	while (stk)
	{
		size++;
		stk = stk->next;
	}
	return (size);
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
