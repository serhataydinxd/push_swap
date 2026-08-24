/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:31:37 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/24 12:04:41 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_any_duplicate(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->data == temp->data)
				return (0);
			temp = temp->next;
		}
		head = head->next;
	}
	return (1);
}

static int	is_flag(char *str)
{
	if (!ft_strcmp(str, "--simple"))
		return (1);
	if (!ft_strcmp(str, "--medium"))
		return (1);
	if (!ft_strcmp(str, "--complex"))
		return (1);
	if (!ft_strcmp(str, "--adaptive"))
		return (1);
	if (!ft_strcmp(str, "--bench"))
		return (1);
	return (0);
}

static t_node	*make_link_list(char **argv)
{
	t_node	*head;
	t_node	*temp;
	size_t	i;
	long	data;

	i = 1;
	head = NULL;
	while (argv[i])
	{
		if (!is_flag(argv[i]))
		{
			data = ft_atol(argv[i]);
			if (data < -2147483648 || data > 2147483647)
				throw_error(head);
			temp = ft_stknew(data);
			if (!temp)
				throw_error(head);
			if (!ft_stkadd_back(&head, temp))
				throw_error(head);
		}
		i++;
	}
	return (head);
}

t_node	*parser(char **argv, t_config *c)
{
	t_node	*head;

	if (parse_flags(argv, c) > 1)
		throw_error(0);
	head = make_link_list(argv);
	if (!check_any_duplicate(head))
		throw_error(head);
	return (head);
}
