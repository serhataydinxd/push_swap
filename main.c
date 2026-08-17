/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/17 07:43:56 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;

	a = parser(argc, argv);
	ft_printf("%u\n", calc_disorder(&a));
	while (a)
	{
		ft_printf("%d\n", a->data);
		if (a->prev)
			ft_printf("%p\n", a->prev);
		ft_printf("%p\n", a->next);
		a = a->next;
	}
}
