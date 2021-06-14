#include "push_swap.h"

int	get_short_way(t_stack s, unsigned int i)
{
	unsigned int	a;
	unsigned int	b;

	a = get_node(s, i) - s.head;
	b = (get_stack_len(s) / 2 + get_stack_len(s) % 2) - 1;
	if (a > b)
	{
		b = s.size;
		return ((b - a) * -1);
	}
	return ((b - a));
}

void	push_min_half_to_b(t_stack *a, t_stack *b, t_indexes *indxs)
{
	unsigned int	i;
	unsigned int	pb_counter;

	i = 0;
	pb_counter = 0;
	while (i <= a->size - indxs->next && a->head->flag == 0)
	{
		if (a->head->index <= indxs->middle)
		{
			pb(b, a);
			pb_counter++;
		}
		else
			ra(*a);
		i++;
	}
}

void	do_index(t_stack *a)
{
	unsigned int	i;
	unsigned int	j;
	t_snode			*min;

	i = 0;
	min = a->head;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->head[j].index == 0)
			{
				if (min->index != 0)
					min = a->head + j;
				if (a->head[j].val < min->val)
					min = a->head + j;
			}
			j++;
		}
		min->index = ++i;
	}
}

t_snode	*get_max_min_elem(t_stack stack, t_snode *start,
							 long (f)(long, long), unsigned int len)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	if (start == stack.begin_p + stack.size)
		return (NULL);
	tmp = start->index;
	while (++i < len)
		tmp = f(tmp, (start + i)->index);
	return (get_node(stack, tmp));
}

unsigned int	get_stack_len(t_stack stack)
{
	return (stack.begin_p + stack.size - stack.head);
}
