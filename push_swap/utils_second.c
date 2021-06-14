#include "push_swap.h"

void	few_rotate(t_stack stack, void r_f(t_stack), unsigned int iter_count)
{
	while (iter_count-- > 0)
		r_f(stack);
}

void	push_to_end(t_stack *dst, t_stack *src, void push(t_stack *, t_stack *),
				 	void rotate(t_stack))
{
	push(dst, src);
	rotate(*dst);
}

void	flush_b_to_end_a(t_stack *b, t_stack *a)
{
	while (b->head != b->begin_p + b->size)
		push_to_end(a, b, pa, ra);
}

void	push_any(t_stack *src, t_stack *dst, void (push)(t_stack *, t_stack *),
				 unsigned int len)
{
	while (0 < len--)
		push(dst, src);
}

t_snode	*get_node(t_stack s, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (i < s.begin_p + s.size - s.head)
	{
		if (s.head[i].index == index)
			return (s.head + i);
		i++;
	}
	return (NULL);
}
