/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:23:10 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/16 11:23:30 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *start = parser(argc, argv);
	while (start)
	{
		printf("%d\n", start->data);
		if (start->prev)
			printf("%p\n", start->prev);
		printf("%p\n", start->next);
		start = start->next;
	}
}
