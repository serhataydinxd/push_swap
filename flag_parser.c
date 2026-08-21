/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:35:50 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/21 18:36:45 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_strat(t_config *c, t_strategy s)
{
	if (!c->st_set)
	{
		c->strategy = s;
		c->st_set = 1;
		return ;
	}
	throw_error();
}

void	parse_flags(char **argv, t_config *c)
{
	int	a;

	a = 1;
	while (argv[a])
	{
		if ((!ft_strcmp(argv[a], "--simple")))
			set_strat(c, SIMPLE);
		else if (!ft_strcmp(argv[a], "--medium"))
			set_strat(c, MEDIUM);
		else if (!ft_strcmp(argv[a], "--complex"))
			set_strat(c, COMPLEX);
		else if (!ft_strcmp(argv[a], "--adaptive"))
			set_strat(c, ADAPTIVE);
		else if (!ft_strcmp(argv[a], "--bench"))
			c->bench_mode = 1;
		a++;
	}
}
