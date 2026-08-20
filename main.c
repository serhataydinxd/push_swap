/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/20 10:10:48 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	char	b;

	a = parser(argc, argv);
	printf("%u\n", calc_disorder(&a));
	chunk_based(&a);
	while (a)
	{
		printf("%d\n", a->data);
		if (a->prev)
			printf("previous %p\n  ", a->prev);
		printf("own %p\n ", a);
		printf("next %p\n", a->next);
		a = a->next;
	}
	b = 'a';
	printf("%p", &b);
}
