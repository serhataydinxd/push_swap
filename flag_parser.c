/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:35:50 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 18:10:02 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strat(t_config *c, t_strategy s)
{
	c->strategy = s;
	c->st_set = 1;
	return (1);
}

int	parse_flags(char **argv, t_config *c)
{
	int	a;
	int	ret;

	a = 1;
	ret = 0;
	while (argv[a])
	{
		if ((!ft_strcmp(argv[a], "--simple")))
			ret += set_strat(c, SIMPLE);
		else if (!ft_strcmp(argv[a], "--medium"))
			ret += set_strat(c, MEDIUM);
		else if (!ft_strcmp(argv[a], "--complex"))
			ret += set_strat(c, COMPLEX);
		else if (!ft_strcmp(argv[a], "--adaptive"))
			ret += set_strat(c, ADAPTIVE);
		else if (!ft_strcmp(argv[a], "--bench"))
			c->bench_mode = 1;
		a++;
	}
	return (ret);
}
