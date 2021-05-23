#include "push_swap.h"

static void rotate(int arr[], unsigned int arr_size)
{
	int				tmp;
	unsigned int	i;

	tmp = 0;
	i = 0;
	tmp = arr[0];
	while (i++ < arr_size - 1)
		arr[i - 1] = arr[i];
	arr[i - 1] = tmp;
}

static void print_rotate(t_stack stack, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	rotate(stack.head, stack.s_size);
}

void	rr(t_stack a, t_stack b)
{
	print_rotate(a, "ss\n");
	rotate(b.head, b.s_size);
}

void	ra(t_stack a)
{
	print_rotate(a, "ra\n");
}

void	rb(t_stack b)
{
	print_rotate(b, "rb\n");
}
