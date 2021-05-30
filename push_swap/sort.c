#include <printf.h>
#include "push_swap.h"

// note: изначально, когда стек 'а' заполнен i = 0, постепенно он увеличивается
// пока не станет равным a.s_size

void print_ab(t_stack *a, t_stack *b)
{
	unsigned	i;
	i = 0;
	printf("a = [ ");
	while (i < (*a).s_size)
	{
		printf("{%d, %u}, ", (*a).begin_p[i].val, (*a).begin_p[i].index);
		i++;
	}
	printf("]\n");
	i = 0;
	printf("b = [ ");
	while (i < (*b).s_size)
	{
		printf("{%d, %u}, ", (*b).begin_p[i].val, (*b).begin_p[i].index);
		i++;
	}
	printf("]\n");
}


void push_min_half_to_a(t_stack *src, t_stack *dst, unsigned len, t_indexes *nbrs)
{
	unsigned	i;
	unsigned	pa_counter;

	i = 0;
	pa_counter = 0;
	while (pa_counter < len && i < src->s_size)
	{
		if (src->head->index <= len || src->head->index == nbrs->next)
		{
			pa(dst, src);
			while (dst->head->index == nbrs->next)
			{
				ra(*dst);
				(nbrs->next)++;
			}
			pa_counter++;
		}
		else
			ra(*src);
		i++;
	}
}

t_stack_node	*find(t_stack s, unsigned index)
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
	print_ab(&a, &b);
	push_b(&a, &b, &nbrs, nbrs.middle);
	print_ab(&a, &b);
	while (b.head != b.begin_p + b.s_size)
	{
		nbrs.maxm = nbrs.middle;
		nbrs.middle = (nbrs.maxm - nbrs.next) / 2 + nbrs.next;
		nbrs.flag++;
		ptr = find(b, nbrs.next);
		if (ptr != NULL)
			push_min_half_to_a(&b, &a, nbrs.middle, &nbrs);
		else
		{
			ptr = find(a, nbrs.next);
			push_any(&a, &b, pb, ptr - a.head);
			ra(a);
			nbrs.next++;
		}
		printf("========== %d ============\n", nbrs.flag);
		print_ab(&a, &b);
	}
	print_ab(&a, &b);
	printf("nbrs = {%d, %d, %d, %d}\n",nbrs.next, nbrs.maxm, nbrs.middle, nbrs.flag);
}
