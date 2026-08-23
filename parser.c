/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:31:37 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/23 14:56:42 by seraydin         ###   ########.fr       */
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

static void	set_data(t_node *temp, char *s)
{
	temp->next = NULL;
	temp->data = ft_atoi(s);
	temp->prev = NULL;
}

static t_node	*make_link_list(char **argv)
{
	t_node	*head;
	t_node	*end;
	t_node	*temp;
	size_t	i;

	i = 1;
	end = NULL;
	head = NULL;
	while (argv[i])
	{
		if (!is_flag(argv[i]))
		{
			temp = malloc(sizeof(t_node));
			if (!temp)
				free_stack(head);
			set_data(temp, argv[i]);
			if (head == NULL)
				head = temp;
			else
				end->next = temp;
			temp->prev = end;
			end = temp;
		}
		i++;
	}
	return (head);
}

t_node	*parser(char **argv, t_config *c)
{
	t_node	*head;

	parse_flags(argv, c);
	head = make_link_list(argv);
	if (!check_any_duplicate(head))
		throw_error();
	return (head);
}
