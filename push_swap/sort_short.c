#include "push_swap.h"

void sort_more_three_less_six(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	push_b(a, b, nbrs, a->s_size - 3);
	sort_three(a, sa, ra, rra);
	if (b->begin_p + b->s_size - b->head == 2 &&
		b->head->index < (b->head + 1)->index)
		sb((*b));
	else if (b->begin_p + b->s_size - b->head == 3)
	{
		sort_three(b, sb, rb, rrb);
		while (b->begin_p + b->s_size - b->head != 0)
		{
			rrb((*b));
			pa(a, b);
		}
	}
	push_any(b, a, pa, a->s_size - 3);
}


void sort_first_two(t_stack stack, void	swap(t_stack))
{
	if (stack.head->index > (stack.head + 1)->index)
		swap(stack);
}

void sort_three(t_stack *stack, void (swap)(t_stack), void (rotate)(t_stack),
				void (r_rotate)(t_stack))
{
	t_stack_node *minim = get_max_min_elem(*stack, stack->head, min, 3);
	t_stack_node *maxim = get_max_min_elem(*stack, stack->head, max, 3);

	if (get_stack_len(*stack) != 3)

	if (count_sorted(stack->head, 3, 0) == 3)
		return;
	if (maxim == stack->head + 2 && minim == stack->head + 1)
		swap(*stack);
	else if (maxim == stack->head)
	{
		if (minim == stack->head + 2)
		{
			swap(*stack);
			r_rotate(*stack);
		}
		else if (minim == stack->head + 1)
			rotate(*stack);
	}
	else if (minim == stack->head && maxim == stack->head + 1)
	{
		swap(*stack);
		rotate(*stack);
	}
	else if (minim == stack->head + 2 && maxim == stack->head + 1)
		r_rotate(*stack);
}