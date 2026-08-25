/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:05:14 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/25 12:10:07 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node(t_node **head, int data)
{
	t_node	*new;

	new = ft_stknew(data);
	if (!new)
		throw_error(*head);
	if (!ft_stkadd_back(head, new))
	{
		free(new);
		throw_error(*head);
	}
}

void	parse_argument(char *arg, t_node **head)
{
	size_t	b;
	int		data;
	int		stat;
	int		parsed;

	b = 0;
	parsed = 0;
	stat = ft_atol(arg, &b, &data);
	while (stat == 1)
	{
		add_node(head, data);
		parsed = 1;
		stat = ft_atol(arg, &b, &data);
	}
	if (stat == -1 || !parsed)
		throw_error(*head);
}
