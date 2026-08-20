/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:01:02 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/20 11:46:17 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;
typedef struct s_counter
{
	size_t			c_sa;
	size_t			c_sb;
	size_t			c_ss;
	size_t			c_pa;
	size_t			c_pb;
	size_t			c_ra;
	size_t			c_rb;
	size_t			c_rr;
	size_t			c_rra;
	size_t			c_rrb;
	size_t			c_rrr;
	size_t			c_total;
}					t_counter;
int					ft_atoi(const char *nptr);
int					check_max_min(int result, const char a, int sign);
void				free_failed_malloc(t_node *head);
void				check_any_duplicate(t_node *head);
t_node				*make_link_list(int argc, char **argv);
t_node				*parser(int argc, char **argv);
t_node				*ft_lstlast(t_node *stk);
unsigned int		ft_lstsize(t_node *stk);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
unsigned int		calc_disorder(t_node **a);
int					ft_atoi(const char *nptr);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
unsigned int		calc_disorder(t_node **a);
void				selection_sort(t_node **a);
void				chunk_based(t_node **a);
#endif
