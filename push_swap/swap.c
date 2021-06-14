#include "push_swap.h"

void	swap(t_snode arr[], unsigned int arr_size)
{
	t_snode	tmp;

	if (arr_size < 1)
		return ;
	else
	{
		tmp = arr[0];
		arr[0] = arr[1];
		arr[1] = tmp;
	}
}

void	ss(t_stack a, t_stack b)
{
	write(1, "ss\n", 3);
	swap(a.head, a.size);
	swap(b.head, b.size);
}

void	print_swap(t_stack stack, const char *msg)
{
	write(1, msg, ft_strlen(msg));
	swap(stack.head, stack.size);
}

void	sb(t_stack b)
{
	print_swap(b, "sb\n");
}

void	sa(t_stack a)
{
	print_swap(a, "sa\n");
}
