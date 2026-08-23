/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:48:36 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 17:59:48 by seraydin         ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[a] && s2[a] && (s1[a] == s2[a]))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

void	throw_error(t_node *a)
{
	free_stack(a);
	ft_printf(2, "Error\n");
	exit(1);
}
