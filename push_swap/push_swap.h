#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h> // todo remove

typedef struct s_stack_node
{
	int		val;
	unsigned	index;
	unsigned	flag;
}				t_stack_node;


typedef struct s_stack
{
	t_stack_node	*begin_p;
	t_stack_node	*head;
	unsigned		s_size;
}				t_stack;

typedef struct s_nbrs
{
	unsigned	middle;
	unsigned	maxm;
	unsigned	flag;
	unsigned	next;
}				t_indexes;

void		sb(t_stack b);
void		sa(t_stack a);
void		ss(t_stack a, t_stack b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
void		ra(t_stack a);
void		rb(t_stack b);
void		rr(t_stack a, t_stack b);
void		rrb(t_stack b);
void		rra(t_stack a);
void		rrr(t_stack a, t_stack b);

void		sort(t_stack a, t_stack b);
int			get_short_way(t_stack s, unsigned i);
void		do_index(t_stack *a);
unsigned	count_sorted(t_stack_node *start, unsigned len, char reverse);
char		is_stack_sorted(t_stack s);
void		push_b(t_stack *a, t_stack *b, t_indexes *indxs, unsigned mid);
void		few_rotate(t_stack stack, void r_f(t_stack), unsigned iter_count);
void		push_to_end(t_stack *dst, t_stack *src,
				  void push(t_stack *, t_stack *), void rotate(t_stack));
void		flush_b_to_end(t_stack *b, t_stack *a);
t_stack_node	*get_node_by_index(t_stack s, unsigned index);
t_stack_node	*get_max_min_elem(t_stack stack, t_stack_node *start,
								long (f)(long, long), unsigned len);
char	is_stack_sorted_cycle(t_stack s, long (*func)(long, long));
//char	is_stack_sorted_cycle(t_stack s);
void	sort_three(t_stack *stack, void (swap)(t_stack), void (rotate)(t_stack),
				void (r_rotate)(t_stack));
void	sort_first_two(t_stack stack, void	swap(t_stack));
void	sort_more_three_less_six(t_stack *a, t_stack *b, t_indexes *nbrs);
void	push_any(t_stack *src, t_stack *dst, void (f)(t_stack *, t_stack *),
				 unsigned len);
unsigned	get_stack_len(t_stack stack);

#endif
