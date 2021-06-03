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

void	sb(t_stack b);
void	sa(t_stack a);
void	ss(t_stack a, t_stack b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack a);
void	rb(t_stack b);
void	rr(t_stack a, t_stack b);
void	rrb(t_stack b);
void	rra(t_stack a);
void	rrr(t_stack a, t_stack b);
void	sort(t_stack a, t_stack b);
int		get_short_way(t_stack s, unsigned pos);
void	do_index(t_stack *a);
unsigned count_sorted(t_stack_node *start, unsigned len, char reverse);
char	is_stack_sorted(t_stack s);
void push_b(t_stack *a, t_stack *b, t_indexes *indxs, unsigned mid);

#endif
