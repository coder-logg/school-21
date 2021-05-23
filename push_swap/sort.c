#include <printf.h>
#include "push_swap.h"

void	push_half_to_b(t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = 0;
	while(i++ < a->s_size / 2)
		pb(b, a);
}

void sort(t_stack a, t_stack b)
{
	unsigned int	i;
	int				tmp;

	push_half_to_b(&a, &b);
	i = 0;
//	while(i < a.s_size / 2)
//	{
//		printf("%d ", b.head[i++]);
//	}
}

//int main()
//{
//	t_stack			a;
//	t_stack			b;
//	int arr[] = {12, 678, 45, 4, -5};
//	a.begin_p = arr;
//	b.begin_p = ft_calloc(5, sizeof(int));
//
//	a.s_size = 5;
//	b.s_size = 5;
//
//	b.head = b.begin_p + 5;
//	a.head = a.begin_p;
//	sort(a, b);
//}