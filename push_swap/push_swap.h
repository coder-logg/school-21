#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				*begin_p;
	int				*head;
	unsigned int	s_size;
}				t_stack;

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

#endif
