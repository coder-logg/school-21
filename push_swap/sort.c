#include <printf.h>
#include "push_swap.h"

// note: изначально, когда стек 'а' заполнен i = 0, постепенно он увеличивается
// пока не станет равным a.s_size

void print_ab(t_stack *a, t_stack *b, t_indexes nbrs)
{
	unsigned i;
	i = 0;
//	fflush(stdout);
	printf("a = [ ");
	while (i < a->s_size)
	{
		if (i % 15 == 0 && i != 0)
			printf("\n");
		if (a->begin_p[i].index != 0)
			printf("\x1b[92m{i=%u, f=%u}, \x1b[0m", a->begin_p[i].index,
				   a->begin_p[i].flag);
		else
			printf("{i=%u, f=%u}, ", a->begin_p[i].index, a->begin_p[i].flag);
		i++;
	}
	printf("]\n");
	i = 0;
	printf("b = [ ");
	while (i < b->s_size)
	{
		if (i % 15 == 0 && i != 0)
			printf("\n");
		if (b->begin_p[i].index != 0)
			printf("\x1b[92m{i=%u, f=%u}, \x1b[0m", b->begin_p[i].index,
				   b->begin_p[i].flag);
		else
			printf("{i=%u, f=%u}, ", b->begin_p[i].index, b->begin_p[i].flag);
		i++;
	}
	printf("]\n");
	printf("nbrs = {next = %d, maxm = %d, mid = %d, flag = %d}\n", nbrs.next,
		   nbrs.maxm, nbrs.middle, nbrs.flag);
	printf("\x1b[0m");
}

t_stack_node *get_node_by_index(t_stack s, unsigned index)
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

t_stack_node *get_max_min_elem(t_stack stack, t_stack_node *start,
							   long (f)(long, long), unsigned len)
{
	unsigned i;
	unsigned tmp;

	i = 0;
	if (start == stack.begin_p + stack.s_size)
		return (NULL);
	tmp = start->index;
	while (++i < len)
		tmp = f(tmp, (start + i)->index);
	return (get_node_by_index(stack, tmp));
}

char is_bigger_elem_in_arr(t_stack stack, unsigned index, unsigned len)
{
	unsigned i;

	i = 0;
	while (len > i)
	{
		if (stack.head[i++].index > index)
			return (1);
	}
	return (0);
}

void push_min_half_to_a(t_stack *src, t_stack *dst, unsigned mid,
						t_indexes *nbrs)
{
	unsigned i;
	unsigned tmp;
	unsigned pa_counter;
	char flag;

	i = 0;
	pa_counter = 0;
	flag = 0;
	tmp = src->begin_p + src->s_size - src->head;
	while (i < tmp)
	{
		if (src->head->index >= mid ||
			(src->head->index == nbrs->next && !flag))
		{
			src->head->flag = nbrs->flag;
			pa(dst, src);
			if (dst->head->index == nbrs->next && !flag)
			{
				flag = 1;
				ra(*dst);
				(nbrs->next)++;
			}
			pa_counter++;
		}
		else if (is_bigger_elem_in_arr(*src, mid, tmp - i))
			rb(*src);
		i++;
	}
}

void push_any(t_stack *src, t_stack *dst, void (f)(t_stack *, t_stack *),
			  unsigned len)
{
	while (0 < len--)
		f(dst, src);
}

unsigned count_elems_with_flag(t_stack stack, unsigned flag)
{
	unsigned i;

	i = 0;
	while (stack.head[i].flag == flag)
		i++;
	return (i);
}

t_indexes get_nbrs(t_indexes *nbrs)
{
	nbrs->maxm = nbrs->middle;
	nbrs->middle = (nbrs->maxm - nbrs->next) / 2 + nbrs->next;
	nbrs->flag++;
	return (*nbrs);
}

t_stack_node	*find_prev(t_stack stack, unsigned  index)
{
	unsigned	i;
	t_stack_node	*prev;
	t_stack_node	previous;
	
	i = 0;
	previous = *(stack.head);
	previous.index = 0;
	prev = &previous;
	while (i < get_stack_len(stack))
	{
		if (prev->index < stack.head[i].index && stack.head[i].index < index)
			prev = stack.head + i;
		i++;
	}
	if (prev->index == 0)
		return (NULL);
	return (prev);
}

t_stack sort_three_less(t_stack *a)
{
	if (a->s_size == 2)
		sort_first_two((*a), sa);
	if (a->s_size == 3)
		sort_three(a, sa, ra, rra);
	return (*a);
}

# include <math.h>
void rotate_by_short_way(t_stack *b, t_stack_node *prev, int sht_way, int prefix)
{
	if ((sht_way == -1 || sht_way == 0))
	{
			few_rotate(*b, rrb,abs(b->head + get_stack_len(*b) - prev - prefix));
//		else if (b->head + get_stack_len(*b) - prev == 2)
//		few_rotate(*b, rrb,b->head + get_stack_len(*b) - prev);

	}
	else if (sht_way == 1 && prev - b->head >= 0 && get_stack_len(*b) != 1)
		few_rotate(*b, rb, prev - b->head + prefix);
}

void push_b_elems_with_same_flag(t_stack *a, t_stack *b, t_indexes *nbrs)
{
	unsigned		tmp_flag;
	t_stack_node	*prev;
	int				short_way;

	tmp_flag = a->head->flag;
	if (count_elems_with_flag((*a), tmp_flag) == 2)
	{
		if (a->head->index > (a->head + 1)->index)
			sa((*a));
		else
			few_rotate((*a), ra, 2);
	}
	else
	{
		while (a->head->flag == tmp_flag)
		{
			if (a->head->index == (*nbrs).next)
			{
				ra(*a);
				nbrs->next++;
			}
			else if ((get_stack_len(*b) != 0 && b->head->index == nbrs->next))
			{
				push_to_end(a, b, pa, ra);
				nbrs->next++;
			}
			else
			{
				prev = find_prev(*b, a->head->index);
				if (prev != NULL)
				{
					rotate_by_short_way(b, prev, get_short_way(*b, prev->index), 1);
				}
				else if (get_stack_len(*b) >= 2)
				{
					t_stack_node *minElem = get_max_min_elem(*b, b->head, min,
															 get_stack_len(*b));
					if (minElem->index > a->head->index)
						rotate_by_short_way(b, minElem, get_short_way(*b, minElem->index), 0);
				}
				pb(b, a);
			}
//			print_ab(a, b, *nbrs);
		}
	}
}

// todo сортировка при например [2, 3, 4, 1], когда нужно только сдвинуть
void sort(t_stack a, t_stack b)
{
	t_indexes nbrs;

//	инициализация
	ft_bzero(&nbrs, sizeof(nbrs));
	nbrs.next = 1;
	nbrs.maxm = a.s_size;
	nbrs.middle = nbrs.maxm / 2 + nbrs.next;
	nbrs.flag = 1;
	if (is_stack_sorted(a))
		return;
//	индексация элементов в порядке возрастания
	do_index(&a);

//	действия если в исходом массиве 2 или 3 или от 3 до 6 элементов
	a = sort_three_less(&a);
	if (a.s_size > 3 && a.s_size <= 6)
		sort_more_three_less_six(&a, &b, &nbrs);
	if (a.s_size == 2 || (a.s_size > 3 && a.s_size <= 6))
		return;
//	если элементов больше шести
//	составляю кучки наверху стека 'а' в порядке возрастанаия по пути складываю первые элементы вниз массива 'a'
//	print_ab(&a, &b, nbrs);
	push_b(&a, &b, &nbrs, nbrs.middle);
//	print_ab(&a, &b, nbrs);
	nbrs = get_nbrs(&nbrs);
	while (b.head != b.begin_p + b.s_size)
	{
		push_min_half_to_a(&b, &a, nbrs.middle, &nbrs);
		nbrs = get_nbrs(&nbrs);
		if (get_stack_len(b) == 2)
			nbrs.middle = get_max_min_elem(b, b.head, max, 2)->index;
//		print_ab(&a, &b, nbrs);
	}

	while (a.head->flag != 0)
	{
		t_stack_node *min_node;
		int short_way;
		unsigned	tmp;

		push_b_elems_with_same_flag(&a, &b, &nbrs);
		min_node = get_max_min_elem(b, b.head, min, get_stack_len(b));
		if (min_node != NULL)
		{
			short_way = get_short_way(b, min_node->index);
			if (short_way == -1)
				few_rotate(b, rrb, b.head + get_stack_len(b) - min_node);
			else
				few_rotate(b, rb, min_node - b.head);
		}
		flush_b_to_end(&b, &a);
		tmp = get_stack_len(b);
		push_any(&b, &a, pa, tmp);
		few_rotate(a, ra, tmp);
		nbrs.next = a.head[get_stack_len(a) - 1].index + 1;
//		print_ab(&a, &b, nbrs);
	}

//		}
//	}
	print_ab(&a, &b, nbrs);
//	printf("|%u|\n", elem_with_one_flag);
//	print_ab(&a, &b, nbrs);
}
