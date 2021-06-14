#include "push_swap.h"

unsigned int	count_sorted(t_snode *start, unsigned int len, char reverse)
{
	unsigned int	i;
	int				tmp;

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

void	rot_by_short_way(t_stack *b, t_snode *elm, int prefix)
{
	int	sht_way;
	int	nbr;

	sht_way = get_short_way(*b, elm->index);
	nbr = b->head + get_stack_len(*b) - elm - prefix;
	if ((sht_way < 0)
		&& get_unsigned(nbr) != get_stack_len(*b))
		few_rotate(*b, rrb, get_unsigned(nbr));
	else if (sht_way >= 0 && elm - b->head >= 0 && get_stack_len(*b) != 1)
		few_rotate(*b, rb, elm - b->head + prefix);
}

t_snode	*find_prev(t_stack stack, unsigned int index)
{
	unsigned int	i;
	t_snode			*prev;
	t_snode			previous;

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

char	is_stack_sorted(t_stack s)
{
	return (count_sorted(s.head, s.begin_p + s.size - s.head, 0)
		== (s.begin_p + s.size - s.head));
}
