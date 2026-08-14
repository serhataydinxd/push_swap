/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:31:37 by ugpolat           #+#    #+#             */
/*   Updated: 2026/08/14 06:21:51 by ugpolat          ###   ########.fr       */
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
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		exit(1);
	while (nptr[i] >= '0' && nptr[i] <= '9' && check_max_min(result, nptr[i],
			sign))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
		exit(1);
	return (result * sign);
}

int	check_max_min(int result, char a, int sign)
{
	long int	min;

	min = (long)__INT_MAX__ + 1;
	if ((result > ((__INT_MAX__) - (a - '0')) / 10))
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
void	check_any_duplicate(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->data == temp->data)
				exit(1);
			temp = temp->next;
		}
		head = head->next;
	}
}
t_node	*make_link_list(int argc, char **argv)
{
	t_node	*head;
	t_node	*end;
	t_node	*temp;
	size_t	i;

	i = 1;
	end = NULL;
	head = NULL;
	while (--argc > 0)
	{
		temp = malloc(sizeof(t_node));
		if (!temp)
			free_failed_malloc(head);
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
	}
	return (head);
}

t_node	*parser(int argc, char **argv)
{
	t_node	*head;

	head = make_link_list(argc, argv);
	check_any_duplicate(head);
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