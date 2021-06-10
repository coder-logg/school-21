#include "push_swap.h"

// note:  push - берет первый элемент вверху src и поместите его вверху dst. Ничего не делать, если src пусто
static void	push(t_stack *dst, t_stack *src)
{
	if (src->begin_p + src->s_size - src->head >= 1)
	{
		dst->head--;
		*(dst->head) = *(src->head);
		ft_bzero(src->head, sizeof(t_stack_node));
		src->head++;
	}
}

static void	print_msg_push(t_stack *dst, t_stack *src, const char *msg)
{
//	todo удалить
//	fflush(stdout);
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