/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/21 20:12:01 by seraydin         ###   ########.fr       */
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

static void	init_config(t_config *c)
{
	c->strategy = ADAPTIVE;
	c->st_set = 0;
	c->bench_mode = 0;
}

static void execute(t_node **a, t_counter *t, t_config *c)
{
	unsigned int	initial_disorder;

	initial_disorder = calc_disorder(a);
	if (c->strategy == ADAPTIVE)
		adaptive(initial_disorder, a, t);
	else if (c->strategy == SIMPLE)
		selection_sort(a, t);
	else if (c->strategy == MEDIUM)
		chunk_based(a, t);
	else if (c->strategy == COMPLEX)
		radix_sort(a, t);
	if (c->bench_mode == 1)
		print_bench(initial_disorder, t, c);

}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_counter	*t;
	t_config	*c;
	//char	b;
	(void)argc;
	t = malloc(sizeof(t_counter));
	if (!t)
		return (1);
	c = malloc(sizeof(t_config));
	if (!c)
		return (1);
	init_counter(t);
	init_config(c);
	a = parser(argv, c);
	//printf("%u\n", calc_disorder(&a));
	execute(&a, t, c);
	free(t);
	free(c);
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
