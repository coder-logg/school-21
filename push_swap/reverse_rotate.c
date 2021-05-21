#include "push_swap.h"
#include <stdio.h>

static void reverse_rotate(int arr[], unsigned int arr_size)
{
	int				tmp;
	unsigned int	i;

	tmp = 0;
	i = 0;
	tmp = arr[arr_size - 1];
	while (--arr_size > 0)
		arr[arr_size] = arr[arr_size - 1];
	arr[0] = tmp;
}

static void print_rrotate(t_stack stack, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	reverse_rotate(stack.stack, stack.s_size);
}

void	rrr(t_stack a, t_stack b)
{
	print_rrotate(a, "rrr\n");
	reverse_rotate(b.stack, b.s_size);
}

void	rra(t_stack a)
{
	print_rrotate(a, "rra\n");
}

void	rrb(t_stack b)
{
	print_rrotate(b, "rrb\n");
}
