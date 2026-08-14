/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:31:37 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/14 03:53:14 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		result;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

t_node	make_link_list(int argc, char **argv)
{
	t_node	*head;
	t_node	*end;
	t_node	*temp;
	size_t	i;

	i = 1;
	end = NULL;
	head = NULL;
	while (argc - 1 > 0)
	{
		temp = malloc(sizeof(t_node));
		temp->next = NULL;
		temp->data = ft_atoi(argv[i]);
		temp->prev = NULL;
		if (head == NULL)
			head = temp;
		else
			end->next = temp;
		temp->prev = end;
		end = temp;
		i++;
		argc--;
	}
	return (head);
}

t_node	*parser(int argc, char **argv)
{
	t_node	*head;

	head = make_link_list(argc, argv);
	return (head);
}
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