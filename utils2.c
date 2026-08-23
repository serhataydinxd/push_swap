/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:29:55 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 19:03:44 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stknew(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->data = data;
	new->index = 0;
	new->next = 0;
	new->prev = 0;
	return (new);
}

int	ft_stkadd_back(t_node **stk, t_node *nw)
{
	t_node	*temp;

	if (!stk || !nw)
		return (0);
	if (!(*stk))
	{
		*stk = nw;
		return (1);
	}
	temp = *stk;
	while (temp->next)
		temp = temp->next;
	temp->next = nw;
	nw->prev = temp;
	return (1);
}

int	check_max_min(long result, const char a, int sign)
{
	long int	min;

	min = -2147483648;
	if ((result > ((2147483647) - (a - '0')) / 10) && sign == 1)
		return (0);
	if (result > (-min - (a - '0')) / 10 && sign == -1)
		return (0);
	return (1);
}

void	free_stack(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
