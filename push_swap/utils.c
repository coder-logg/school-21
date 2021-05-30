#include "push_swap.h"

int get_short_way(t_stack s, unsigned pos)
{
	if (pos > s.s_size / 2)
		return (-1);
	else
		return (1);
}

//  a->s_size / 2 + 1
void push_b(t_stack *a, t_stack *b, t_indexes *indxs, unsigned len)
{
	unsigned	i;
	unsigned	pb_counter;

	i = 0;
	pb_counter = 0;
	while (pb_counter < len && i < a->s_size)
	{
		if (a->head->index <= len || a->head->index == indxs->next)
		{
			pb(b, a);
			while (a->head->index == indxs->next)
			{
				ra(*a);
				(indxs->next)++;
			}
			pb_counter++;;
		}
		else
			ra(*a);
		i++;
	}
}

void do_index(t_stack *a)
{
	unsigned int i;
	unsigned int j;
	t_stack_node *min;

	i = 0;
	min = a->head;
	while (i < a->s_size)
	{
		j = 0;
		while (j < a->s_size)
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

unsigned count_sorted(t_stack_node *start, unsigned len, char reverse)
{
	unsigned i;

	i = 0;
	if (reverse)
	{
		while (len > i && start[i].val > start[i + 1].val)
			i++;
	}
	else
	{
		while (len > i && start[i].val < start[i + 1].val)
			i++;
	}
	return (i);
}

char	is_stack_sorted(t_stack s)
{
	return (count_sorted(s.head, s.begin_p + s.s_size - s.head, 0)
			== s.begin_p + s.s_size - s.head);
}