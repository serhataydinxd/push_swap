/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 02:11:37 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/23 02:11:48 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_min(int result, const char a, int sign)
{
	long int	min;

	min = -2147483648;
	if ((result > ((2147483647) - (a - '0')) / 10) && sign == 1)
		throw_error();
	if (result > (-min - (a - '0')) / 10 && sign == -1)
		throw_error();
	return (1);
}

void	free_failed_malloc(t_node *head)
{
	t_node *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	exit(1);
}