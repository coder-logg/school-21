#include "push_swap.h"

char	is_stack_sorted_cycle(t_stack s)
{
	t_snode			*min_node;
	unsigned int	prev;
	unsigned int	next;
	unsigned int	i;

	if (is_stack_sorted(s))
		return (1);
	min_node = get_max_min_elem(s, s.head, min, get_stack_len(s));
	i = min_node - s.head;
	prev = s.head[i++].index;
	if (i > get_stack_len(s) - 1)
		i = 0;
	next = s.head[i++].index;
	while (s.head[i].index != min_node->index)
	{
		if (next < prev)
			return (0);
		if (i++ > get_stack_len(s) - 1)
			i = 0;
		prev = next;
		next = s.head[i].index;
	}
	return (1);
}

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

void	rot_by_shrt_way(t_stack *b, t_snode *elm, int prefix, char s_name)
{
	int		sht_way;
	int		nbr;
	void	(*r_f[2])(t_stack);

	if (s_name == 'b')
	{
		r_f[0] = rb;
		r_f[1] = rrb;
	}
	else if (s_name == 'a')
	{
		r_f[0] = ra;
		r_f[1] = rra;
	}
	sht_way = get_short_way(*b, elm->index);
	nbr = b->head + get_stack_len(*b) - elm - prefix;
	if ((sht_way < 0)
		&& get_unsigned(nbr) != get_stack_len(*b))
		few_rotate(*b, r_f[1], get_unsigned(nbr));
	else if (sht_way >= 0 && elm - b->head >= 0 && get_stack_len(*b) != 1)
		few_rotate(*b, r_f[0], elm - b->head + prefix);
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
	return (count_sorted(s.head, get_stack_len(s), 0) == get_stack_len(s));
}
