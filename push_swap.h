/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugpolat@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:01:02 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/23 16:10:47 by ugpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

typedef struct s_config
{
	t_strategy		strategy;
	t_strategy		a_strategy;
	int				st_set;
	int				bench_mode;
}					t_config;
typedef struct s_chunk
{
	int				*sorted_array;
	int				total_numbers;
	int				numbers_per_chunk;
	int				chunk_min;
	int				chunk_max;
}					t_chunk;


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

void				fake_selection_sort(t_node **a, t_node **b, t_counter *t);
int					ft_atoi(const char *nptr);
int					check_max_min(int result, const char a, int sign);
void				free_stack(t_node *head);
t_node				*parser(char **argv, t_config *c);
t_node				*ft_lstlast(t_node *stk);
unsigned int		ft_lstsize(t_node *stk);
void				ra(t_node **a, t_counter *t);
void				rb(t_node **b, t_counter *t);
void				rr(t_node **a, t_node **b, t_counter *t);
void				rra(t_node **a, t_counter *t);
void				rrb(t_node **b, t_counter *t);
void				rrr(t_node **a, t_node **b, t_counter *t);
unsigned int		calc_disorder(t_node **a);
void				pa(t_node **a, t_node **b, t_counter *t);
void				pb(t_node **a, t_node **b, t_counter *t);
void				sa(t_node **a, t_counter *t);
void				sb(t_node **a, t_counter *t);
void				ss(t_node **a, t_node **b, t_counter *t);
void				selection_sort(t_node **a, t_counter *t);
void				chunk_based(t_node **a, t_counter *t);
void				radix_sort(t_node **a, t_counter *t);
int					is_sorted(t_node *a);
int					ft_strcmp(const char *s1, const char *s2);
void				throw_error(void);
void				parse_flags(char **argv, t_config *c);
void				adaptive(unsigned int in_dis, t_node **a, t_counter *t,
						t_config *c);
void				print_bench(unsigned int in_dis, t_counter *t, t_config *c);
#endif
