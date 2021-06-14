#include "push_swap.h"

char	is_bigger_elem_in_arr(t_stack stack, unsigned int index,
							  unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (len > i)
	{
		if (stack.head[i++].index > index)
			return (1);
	}
	return (0);
}

void	pa_min_half(t_stack *src, t_stack *dst, unsigned int mid,
					t_indexes *nbrs)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	pa_counter;

	i = 0;
	pa_counter = 0;
	len = get_stack_len(*src);
	while (i < len)
	{
		if (src->head->index >= mid || (src->head->index == nbrs->next))
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
		else if (is_bigger_elem_in_arr(*src, mid, len - i))
			rb(*src);
		i++;
	}
}

int	rot_next_in_head_to_end(const t_stack *a, t_indexes *nbrs)
{
	int	res;

	res = 0;
	if (a->head[0].index == nbrs->next + 1 && a->head[1].index == nbrs->next)
	{
		sa(*a);
		ra(*a);
		ra(*a);
		nbrs->next += 2;
		res = 1;
	}
	else if (a->head->index == nbrs->next)
	{
		ra(*a);
		nbrs->next++;
		res = 1;
	}
	return (res);
}
