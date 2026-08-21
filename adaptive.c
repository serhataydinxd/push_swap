/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:51:08 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/21 20:37:39 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(unsigned int in_dis, t_node **a, t_counter *t, t_config *c)
{

	if (!a || !*a || !(*a)->next)
		return ;
	if (in_dis < 2000)
	{
		c->a_strategy = SIMPLE;
		selection_sort(a, t);
	}
	else if (in_dis < 4000)
	{
		c->a_strategy = MEDIUM;
		chunk_based(a, t);
	}
	else
	{
		c->a_strategy = COMPLEX;
		radix_sort(a, t);
	}
}
