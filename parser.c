/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:31:37 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/21 20:10:47 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_min(int result, const char a, int sign)
{
	long int	min;

	min = -2147483648;
	if ((result > ((2147483647) - (a - '0')) / 10))
		return (0);
	if (result > (min - (a - '0')) / 10 && sign == -1)
		return (0);
	return (1);
}

void	free_failed_malloc(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	exit(1);
}

int	check_any_duplicate(t_node *head)
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

t_node	*make_link_list(char **argv)
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
				free_failed_malloc(head);
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
		return (0);
	return (head);
}
