#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	if (src->begin_p + src->size - src->head >= 1)
	{
		dst->head--;
		*(dst->head) = *(src->head);
		ft_bzero(src->head, sizeof(t_snode));
		src->head++;
	}
}

static void	print_msg_push(t_stack *dst, t_stack *src, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	push(dst, src);
}

void	pa(t_stack *a, t_stack *b)
{
	print_msg_push(a, b, "pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	print_msg_push(b, a, "pb\n");
}
