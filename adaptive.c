/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:51:08 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/21 20:00:43 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(unsigned int in_dis, t_node **a, t_counter *t)
{

	if (!a || !*a || !(*a)->next)
		return ;
	if (in_dis < 2000)
		selection_sort(a, t);
	else if (in_dis < 5000)
		chunk_based(a, t);
	else
		radix_sort(a, t);
}
