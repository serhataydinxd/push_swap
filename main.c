/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/20 02:13:11 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;

	a = parser(argc, argv);
	printf("%u\n", calc_disorder(&a));
	selection_sort(&a);
	while (a)
	{
		printf("%d\n", a->data);
		if (a->prev)
			printf("%p\n", a->prev);
		printf("%p\n", a->next);
		a = a->next;
	}
}
