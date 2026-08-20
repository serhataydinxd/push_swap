/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/20 19:37:12 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	init_counter(t_counter *t)
{
	t->c_pa = 0;
	t->c_pb = 0;
	t->c_ra = 0;
	t->c_rb = 0;
	t->c_rr = 0;
	t->c_sa = 0;
	t->c_sb = 0;
	t->c_ss = 0;
	t->c_rra = 0;
	t->c_rrb = 0;
	t->c_rrr = 0;
	t->c_total = 0;
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_counter	*t;
	t_config	*c;
	//char	b;

	a = parser(argc, argv);
	printf("%u\n", calc_disorder(&a));
	t = malloc(sizeof(t_counter));
	if (!t)
		return (1);
	c = malloc(sizeof(t_config));
	if (!c)
		return (1);
	init_counter(t);
	radix_sort(&a, t);
	free(t);
	//while (a)
	//{
		//printf("%d\n", a->data);
		//if (a->prev)
			//printf("previous %p\n  ", a->prev);
		//printf("own %p\n ", a);
		//printf("next %p\n", a->next);
		//a = a->next;
	//}
	//b = 'a';
	//printf("%p", &b);
}
