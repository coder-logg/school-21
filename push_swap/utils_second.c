#include "push_swap.h"

void few_rotate(t_stack stack, void r_f(t_stack), unsigned iter_count)
{
	while (iter_count-- > 0)
		r_f(stack);
}

void push_to_end(t_stack *dst, t_stack *src, void push(t_stack *, t_stack *),
				 	void rotate(t_stack))
{
	push(dst, src);
	rotate(*dst);
}

void flush_b_to_end(t_stack *b, t_stack *a)
{
	while (b->head != b->begin_p + b->s_size)
		push_to_end(a, b, pa, ra);
}

char	is_stack_resorted(t_stack s)
{
	return (count_sorted(s.head, s.begin_p + s.s_size - s.head, 1)
			== (s.begin_p + s.s_size - s.head));
}