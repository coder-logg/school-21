#include "push_swap.h"

static void reverse_rotate(t_stack_node arr[], unsigned int arr_size)
{
	t_stack_node	tmp;
	unsigned int	i;

	i = 0;
	tmp = arr[arr_size - 1];
	while (--arr_size > 0)
		arr[arr_size] = arr[arr_size - 1];
	arr[0] = tmp;
}

static void print_rrotate(t_stack stack, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	reverse_rotate(stack.head, stack.begin_p + stack.s_size - stack.head);
}

void	rrr(t_stack a, t_stack b)
{
	print_rrotate(a, "rrr\n");
	reverse_rotate(b.head, b.s_size);
}

void	rra(t_stack a)
{
	print_rrotate(a, "rra\n");
}

void	rrb(t_stack b)
{
	print_rrotate(b, "rrb\n");
}
