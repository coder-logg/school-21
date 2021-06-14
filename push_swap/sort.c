#include "push_swap.h"

t_indexes	get_nbrs(t_indexes *nbrs)
{
	nbrs->maxm = nbrs->middle;
	nbrs->middle = (nbrs->maxm - nbrs->next) / 2 + nbrs->next;
	nbrs->flag++;
	return (*nbrs);
}

void	push_b_elems_with_same_flag(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	unsigned int	tmp_flag;
	t_snode			*prev;

	tmp_flag = a->head->flag;
	while (a->head->flag == tmp_flag)
	{
		if (rot_next_in_head_to_end(a, nbrs))
			;
		else if ((get_stack_len(*b) != 0 && b->head->index == nbrs->next))
		{
			push_to_end(a, b, pa, ra);
			nbrs->next++;
		}
		else
		{
			prev = find_prev(*b, a->head->index);
			if (prev != NULL)
				rot_by_short_way(b, prev, 1);
			else if (get_stack_len(*b) >= 2)
				rot_by_short_way(b, get_max_min_elem(*b, b->head, min,
						get_stack_len(*b)), 0);
			pb(b, a);
		}
	}
}

void	flush_b_by_min_hulf(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	while (get_stack_len(*b) != 0)
	{
		(*nbrs) = get_nbrs(nbrs);
		pa_min_half(b, a, nbrs->middle, nbrs);
	}
}

void	do_sort(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	t_snode	*min_node;

	while (nbrs->next < a->size)
	{
		nbrs->middle = a->size;
		(*nbrs) = get_nbrs(nbrs);
		push_min_half_to_b(a, b, nbrs);
		few_rotate((*a), rra,
			 a->begin_p + a->size - get_node((*a), nbrs->next - 1) - 1);
		flush_b_by_min_hulf(a, b, nbrs);
		while (a->head->flag != 0 && !is_stack_sorted((*a)))
		{
			push_b_elems_with_same_flag(a, b, nbrs);
			min_node = get_max_min_elem(*b, b->head, min, get_stack_len(*b));
			if (min_node != NULL)
				rot_by_short_way(b, min_node, 0);
			else if (get_stack_len(*b) >= 2)
				rot_by_short_way(b, get_max_min_elem((*b), b->head, min,
						get_stack_len(*b)), 0);
			nbrs->next += get_stack_len((*b));
			flush_b_to_end_a(b, a);
		}
		while (rot_next_in_head_to_end(a, nbrs))
			;
	}
}

// todo сортировка при например [2, 3, 4, 1], когда нужно только сдвинуть
void	sort(t_stack a, t_stack b)
{
	t_indexes	nbrs;

	ft_bzero(&nbrs, sizeof(nbrs));
	nbrs.next = 1;
	nbrs.maxm = a.size;
	nbrs.middle = nbrs.maxm / 2 + nbrs.next;
	nbrs.flag = 1;
	if (is_stack_sorted(a))
		return ;
	do_index(&a);
	if (a.size == 2 || (a.size >= 3 && a.size <= 6))
	{
		sort_short(&a, &b, &nbrs);
		return ;
	}
	push_min_half_to_b(&a, &b, &nbrs);
	while (get_stack_len(b) != 0)
	{
		nbrs = get_nbrs(&nbrs);
		pa_min_half(&b, &a, nbrs.middle, &nbrs);
	}
	do_sort(&a, &b, &nbrs);
}
