#include "push_swap.h"

int	get_short_way(t_stack s, unsigned i)
{
	unsigned a = get_node_by_index(s, i) - s.head;
	unsigned b = (get_stack_len(s) / 2 + get_stack_len(s) % 2) - 1;
	if (a > b)
		return (-1);
	else if (a < b)
		return (1);
	else
		return (0);
}

//  a->s_size / 2 + 1
void	push_b(t_stack *a, t_stack *b, t_indexes *indxs, unsigned mid)
{
	unsigned	i;
	unsigned	pb_counter;

	i = 0;
	pb_counter = 0;
	while (pb_counter < mid && i < a->s_size)
	{
		if (a->head->index <= mid || a->head->index == indxs->next)
		{
			pb(b, a);
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

unsigned get_stack_len(t_stack stack)
{
	return (stack.begin_p + stack.s_size - stack.head);
}

//unsigned get_short_way_nbr_oper(t_stack s, unsigned i)
//{
//
//}