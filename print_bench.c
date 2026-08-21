/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:13:21 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/21 20:15:05 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	print_bench(unsigned int in_dis, t_counter *t, t_config *c)
{
	(void) t;
	(void) c;
	ft_printf(2, "[bench] disorder: %u.%u%%\n", (in_dis / 100), (in_dis % 100));
}
