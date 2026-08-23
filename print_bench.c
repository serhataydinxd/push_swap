/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:13:21 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 14:37:52 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static void	print_strategy(t_config *c)
{
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
}

void	print_bench(unsigned int in_dis, t_counter *t, t_config *c)
{
	unsigned int	first;
	unsigned int	second;

	first = in_dis / 100;
	second = in_dis % 100;
	ft_printf(2, "[bench] disorder: %u.", first);
	if (second < 10)
		ft_printf(2, "0");
	ft_printf(2, "%u%%\n", second);
	print_strategy(c);
	ft_printf(2, "[bench] total_ops: %u\n", (unsigned int)t->c_total);
	ft_printf(2, "[bench] sa: %u sb: %u ss: %u pa: %u pb: %u\n",
		(unsigned int)t->c_sa, (unsigned int)t->c_sb, (unsigned int)t->c_ss,
		(unsigned int)t->c_pa, (unsigned int)t->c_pb);
	ft_printf(2, "[bench] ra: %u rb: %u rr: %u rra: %u rrb: %u rrr: %u\n",
		(unsigned int)t->c_ra, (unsigned int)t->c_rb, (unsigned int)t->c_rr,
		(unsigned int)t->c_rra, (unsigned int)t->c_rrb, (unsigned int)t->c_rrr);
}
