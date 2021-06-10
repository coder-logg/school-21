#include "push_swap.h"


// когда func = min проверяется на отсортированность,
// func = max на обратную отсортированность
char is_stack_sorted_cycle(t_stack s, long (*func)(long, long))
{
	t_stack_node	*max_node;
	int				tmp;
	unsigned		i;

	max_node = get_max_min_elem(s, s.head, func, s.begin_p + s.s_size - s.head);
	i = max_node - s.head + 1;
	while (s.head[i].index != max_node->index)
	{
		tmp = s.head[i++].val;
		if (s.head + i != s.begin_p + s.s_size)
			i = 0;
		if (func(s.head[i].val, tmp) == tmp)
			return (0);
	}
	return (1);
}

unsigned count_sorted(t_stack_node *start, unsigned len, char reverse)
{
	unsigned	i;
	int			tmp;

	i = 0;
	if (reverse)
	{
		tmp = start[i++].val;
		while (len > i && tmp > start[i].val)
		{
			tmp = start[i].val;
			i++;
		}
	}
	else
	{
		tmp = start[i++].val;
		while (len > i && start[i].val > tmp)
		{
			tmp = start[i].val;
			i++;
		}
	}
	return (i);
}

char	is_stack_sorted(t_stack s)
{
	return (count_sorted(s.head, s.begin_p + s.s_size - s.head, 0)
			== (s.begin_p + s.s_size - s.head));
}

//int check_sorting(t_stack s)
//{
//
//}