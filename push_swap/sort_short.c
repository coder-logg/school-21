#include "push_swap.h"

void	sort_more_three_less_six(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	nbrs->middle = a->size - 3;
	push_min_half_to_b(a, b, nbrs);
	sort_three(a, sa, ra, rra);
	if (b->begin_p + b->size - b->head == 2
		&& b->head->index < (b->head + 1)->index)
		sb((*b));
	else if (b->begin_p + b->size - b->head == 3)
	{
		sort_three(b, sb, rb, rrb);
		while (b->begin_p + b->size - b->head != 0)
		{
			rrb((*b));
			pa(a, b);
		}
	}
	push_any(b, a, pa, a->size - 3);
}

void	sort_first_two(t_stack stack, void	swap(t_stack))
{
	if (stack.head->index > (stack.head + 1)->index)
		swap(stack);
}

void	sort_short(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	if (a->size == 2)
		sort_first_two(*a, sa);
	if (a->size == 3)
		sort_three(a, sa, ra, rra);
	if (a->size > 3 && a->size <= 6)
		sort_more_three_less_six(a, b, nbrs);
}

void	sort_three(t_stack *stack, void (swap)(t_stack), void (rotate)(t_stack),
				void (r_rotate)(t_stack))
{
	t_snode	*minim;
	t_snode	*maxim;

	minim = get_max_min_elem(*stack, stack->head, min, 3);
	maxim = get_max_min_elem(*stack, stack->head, max, 3);
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
