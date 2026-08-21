/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:13:21 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/21 20:52:41 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	print_bench(unsigned int in_dis, t_counter *t, t_config *c)
{
	(void) t;
	(void) c;
	ft_printf(2, "[bench] disorder: %u.%u%%\n", (in_dis / 100), (in_dis % 100));
	if (c->st_set)
	{
		if (c->strategy == SIMPLE)
			ft_printf(2, "[bench] strategy: Simple / O(n^2)\n");
		else if (c->strategy == MEDIUM)
			ft_printf(2, "[bench] strategy: Medium / O(n*sqrt(n))\n");
		else if (c->strategy == COMPLEX)
			ft_printf(2, "[bench] strategy: Complex / O(n*log(n))\n");
	}
	else
	{
		if (c->a_strategy == SIMPLE)
			ft_printf(2, "[bench] strategy: Adaptive / O(n^2)\n");
		else if (c->a_strategy == MEDIUM)
			ft_printf(2, "[bench] strategy: Adaptive / O(n*sqrt(n))\n");
		else if (c->a_strategy == COMPLEX)
			ft_printf(2, "[bench] strategy: Adaptive / O(n*log(n))\n");
	}
	ft_printf(2, "[bench] total_ops: %d\n", t->c_total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", t->c_sa, t->c_sb, t->c_ss, t->c_pa, t->c_pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", t->c_ra, t->c_rb, t->c_rr, t->c_rra, t->c_rrb, t->c_rrr);
}
