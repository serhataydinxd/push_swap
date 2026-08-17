/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/17 16:45:44 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*start;

	start = parser(argc, argv);
	ft_printf(1, "%u\n", calc_disorder(&start));
	while (start)
	{
		ft_printf(1, "%d\n", start->data);
		if (start->prev)
			ft_printf(1, "%p\n", start->prev);
		ft_printf(1, "%p\n", start->next);
		start = start->next;
	}
}
