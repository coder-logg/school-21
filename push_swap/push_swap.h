#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int				val;
	unsigned int	index;
	unsigned int	flag;
}				t_snode;

typedef struct s_stack
{
	t_snode				*begin_p;
	t_snode				*head;
	unsigned int		size;
}				t_stack;

typedef struct s_nbrs
{
	unsigned int	middle;
	unsigned int	maxm;
	unsigned int	flag;
	unsigned int	next;
}				t_indexes;

void			sb(t_stack b);
void			sa(t_stack a);
void			ss(t_stack a, t_stack b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);
void			ra(t_stack a);
void			rb(t_stack b);
void			rr(t_stack a, t_stack b);
void			rrb(t_stack b);
void			rra(t_stack a);
void			rrr(t_stack a, t_stack b);

void			sort(t_stack a, t_stack b);
int				get_short_way(t_stack s, unsigned int i);
void			do_index(t_stack *a);
unsigned int	count_sorted(t_snode *start, unsigned int len, char reverse);
char			is_stack_sorted(t_stack s);
void			push_min_half_to_b(t_stack *a, t_stack *b, t_indexes *indxs);
void			few_rotate(t_stack stack, void r_f(t_stack),
					unsigned int iter_count);
void			push_to_end(t_stack *dst, t_stack *src,
					void push(t_stack *, t_stack *), void rotate(t_stack));
void			flush_b_to_end_a(t_stack *b, t_stack *a);
t_snode			*get_node(t_stack s, unsigned int index);
t_snode			*get_max_min_elem(t_stack stack, t_snode *start,
					 long (f)(long, long), unsigned int len);
void			sort_three(t_stack *stack, void (swap)(t_stack),
					void (rotate)(t_stack), void (r_rotate)(t_stack));
void			sort_short(t_stack *a, t_stack *b, t_indexes *nbrs);
void			push_any(t_stack *src, t_stack *dst,
					void (push)(t_stack *, t_stack *), unsigned int len);
unsigned int	get_stack_len(t_stack stack);
t_snode			*find_prev(t_stack stack, unsigned int index);
void			rot_by_shrt_way(t_stack *b, t_snode *elm, int prefx, char snm);
void			pa_min_half(t_stack *src, t_stack *dst, unsigned int mid,
					t_indexes *nbrs);
int				rot_next_in_head_to_end(const t_stack *a, t_indexes *nbrs);
void			fill_ab(int arr[], char ***argv, t_stack *a, t_stack *b);
void			if_one_arg(int argc, char ***argv, int *i);
void			freee(char **argv, t_stack *a, t_stack *b, int i);
void			error(const char *msg);
char			check_digits(char *str);
char			is_stack_sorted_cycle(t_stack s);

#endif
