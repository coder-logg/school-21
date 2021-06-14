#include "push_swap.h"

static void	rotate(t_snode arr[], unsigned int arr_size)
{
	t_snode			tmp;
	unsigned int	i;

	if (arr_size == 0)
		return ;
	i = 0;
	tmp = arr[0];
	while (i++ < arr_size - 1)
		arr[i - 1] = arr[i];
	arr[i - 1] = tmp;
}

static void	print_rotate(t_stack stack, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	rotate(stack.head, stack.begin_p + stack.size - stack.head);
}

void	rr(t_stack a, t_stack b)
{
	print_rotate(a, "ss\n");
	rotate(b.head, b.size);
}

void	ra(t_stack a)
{
	print_rotate(a, "ra\n");
}

void	rb(t_stack b)
{
	print_rotate(b, "rb\n");
}
