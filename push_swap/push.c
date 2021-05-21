#include "push_swap.h"

// note:  push - берет первый элемент вверху src и поместите его вверху dst. Ничего не делать, если src пусто
static void	push(int dst[], int src[], unsigned int src_size)
{
	if (src_size >= 1)
		dst[0] = src[0];
}

static void	print_msg_push(t_stack dst, t_stack src, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	push(dst.stack, src.stack, src.s_size);
}

void	pa(t_stack a, t_stack b)
{
	print_msg_push(a, b, "sa\n");
}

void	pb(t_stack b, t_stack a)
{
	print_msg_push(b, a, "sb\n");
}