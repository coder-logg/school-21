#include <printf.h>
#include "push_swap.h"

// note: изначально, когда стек 'а' заполнен i = 0, постепенно он увеличивается
// пока не станет равным a.s_size

void print_ab(t_stack *a, t_stack *b, t_indexes nbrs)
{
	unsigned	i;
	i = 0;
	printf("a = [ ");
	while (i < (*a).s_size)
	{
		if (i % 15 == 0 && i != 0)
			printf("\n");
		if (a->begin_p[i].index != 0)
			printf("\x1b[92m{v=%d, i=%u, f=%u}, \x1b[0m", a->begin_p[i].val, a->begin_p[i].index, a->begin_p[i].flag);
		else
			printf("{v=%d, i=%u, f=%u}, ", (*a).begin_p[i].val, (*a).begin_p[i].index, a->begin_p[i].flag);
		i++;
	}
	printf("]\n");
	i = 0;
	printf("b = [ ");
	while (i < (*b).s_size)
	{
		if (i % 15 == 0 && i != 0)
			printf("\n");
		if (b->begin_p[i].index != 0)
			printf("\x1b[92m{v=%d, i=%u, f=%u}, \x1b[0m", (*b).begin_p[i].val, (*b).begin_p[i].index, b->begin_p[i].flag);
		else
			printf("{v=%d, i=%u, f=%u}, ", (*b).begin_p[i].val, (*b).begin_p[i].index, b->begin_p[i].flag);
		i++;
	}
	printf("]\n");
	printf("nbrs = {next = %d, maxm = %d, mid = %d, flag = %d}\n",nbrs.next, nbrs.maxm, nbrs.middle, nbrs.flag);
	printf("\x1b[0m");
}


void push_min_half_to_a(t_stack *src, t_stack *dst, unsigned mid, t_indexes *nbrs)
{
	unsigned	i;
	unsigned	pa_counter;

	i = 0;
	pa_counter = 0;
	while (pa_counter < mid && pa_counter < src->begin_p + src->s_size - src->head && i < src->s_size)
	{
		if (src->head->index >= mid || src->head->index == nbrs->next)
		{
			src->head->flag = nbrs->flag;
			pa(dst, src);
			while (dst->head->index == nbrs->next)
			{
				ra(*dst);
				(nbrs->next)++;
			}
			pa_counter++;
		}
		else
			rb(*src);
		i++;
	}
}

t_stack_node	*get_node_by_index(t_stack s, unsigned index)
{
	unsigned i;

	i = 0;
	while (i < s.begin_p + s.s_size - s.head)
	{
		if (s.head[i].index == index)
			return (s.head + i);
		i++;
	}
	return (NULL);
}

void push_any(t_stack *src, t_stack *dst, void (f)(t_stack *, t_stack *), unsigned len)
{
	while (0 < len--)
		f(dst, src);
}

t_stack_node *get_max_min_elem(t_stack stack,t_stack_node *start, long (f)(long, long), unsigned len)
{
	unsigned i;
	unsigned tmp;

	i = 0;
	tmp = start->index;
	while (++i < len)
		tmp = f(tmp, (start + i)->index);
	return (get_node_by_index(stack, tmp));
}

void sort_three(t_stack *stack, void (swap)(t_stack), void (rotate)(t_stack), void (r_rotate)(t_stack))
{
	t_stack_node	*minim = get_max_min_elem(*stack, stack->head, min, 3);
	t_stack_node	*maxim = get_max_min_elem(*stack, stack->head, max, 3);


	if (count_sorted(stack->head, 3, 0) == 3)
		return ;
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

// todo сортировка при например [2, 3, 4, 1], когда нужно только сдвинуть
void	sort(t_stack a, t_stack b)
{
	t_indexes		nbrs;
	t_stack_node	*ptr;

	ft_bzero(&nbrs, sizeof(nbrs));
	nbrs.next = 1;
	nbrs.maxm = a.s_size;
	nbrs.middle = nbrs.maxm / 2 + nbrs.next;
	nbrs.flag = 1;
	if (is_stack_sorted(a))
		return ;
	do_index(&a);
//	print_ab(&a, &b);
	if (a.s_size == 2 && a.head->index > (a.head + 1)->index)
		sa(a);
	if (a.s_size == 3)
		sort_three(&a, sa, ra, rra);
	if (a.s_size > 3 && a.s_size <=  6)
	{
		push_b(&a, &b, &nbrs, a.s_size - 3);
		print_ab(&a, &b, nbrs);
		sort_three(&a, sa, ra, rra);
//		print_ab(&a, &b);
		if (b.begin_p + b.s_size - b.head == 2 && b.head->index < (b.head + 1)->index)
			sb(b);
		else if (b.begin_p + b.s_size - b.head == 3)
		{
			sort_three(&b, sb, rb, rrb);
			while (b.begin_p + b.s_size - b.head != 0)
			{
				rrb(b);
				pa(&a, &b);
			}
		}
		push_any(&b, &a, pa, a.s_size - 3);
//		print_ab(&a, &b);
	}
	if (a.s_size == 2 || (a.s_size > 3 && a.s_size <=  6))
		return ;
	push_b(&a, &b, &nbrs, nbrs.middle);
	print_ab(&a, &b, nbrs);
	while (b.head != b.begin_p + b.s_size)
	{
		nbrs.maxm = nbrs.middle;
		nbrs.middle = (nbrs.maxm - nbrs.next) / 2 + nbrs.next;
		nbrs.flag++;
		ptr = get_node_by_index(b, nbrs.next);
		push_min_half_to_a(&b, &a, nbrs.middle, &nbrs);
		print_ab(&a, &b, nbrs);
	}
//		print_ab(&a, &b, nbrs);
//	printf("nbrs = {next = %d, maxm = %d, mid = %d, flag = %d}\n",nbrs.next, nbrs.maxm, nbrs.middle, nbrs.flag);
}
