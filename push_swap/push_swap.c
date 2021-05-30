#include "push_swap.h"

void	error()
{
	write(1, "Error\n", 6);
	exit(1);
}

char	check_digits(char *str)
{
	unsigned	i;

	i = 0;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 || i > 11)
			return (0);
		i++;
	}
	return (1);
}

void	check_duplicates(t_stack_node arr[],  unsigned int arr_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < arr_size - 1)
	{
		j = 0;
		while(j++ < arr_size - 1)
		{
			if (i == j)
				continue ;
			if (arr[i].val == arr[j].val)
				error();
		}
		i++;
	}
}

t_stack init_stack(unsigned size)
{
	t_stack res;
	res.s_size = size;
	res.begin_p = ft_calloc(size, sizeof(t_stack_node));
	res.head = res.begin_p + size;
	return (res);
}

int	check(unsigned size, char **args)
{
	unsigned	i;
	i = 0;
	while (i < size)
	{
		if (!check_digits(args[i]))
			error();
		else if (str_only_chr(args[i], " -+0123456789"))
			return (1);
		else
			error();

		i++;
	}
	return (0);
}

// note: голова стека - левый конец массива, конец стека - правый конец массива

// если не прошел check_digits -> если в строке есть пробел -> split -> каждую
// строку котрую вернул split проверяю на check_digits
int main(int argc, char **argv)
{
	unsigned	i;
	long		tmp;
	t_stack		a;
	t_stack		b;
	char		**args;


	if (argc > 1)
	{
//		check(--argc, ++argv);
		argc--;argv++;
		b = init_stack(argc);
		a = init_stack(argc);
		a.head = a.begin_p;
		i = 0;
		while ((int)i < argc)
		{
			if (!check_digits(argv[i]))
			{
				error();
			}
//			else
				tmp = ft_atoi(argv[i]);
			if (tmp > 2147483647 || tmp < -2147483648)
				error();
			a.begin_p[i++].val = tmp;
		}
		check_duplicates(a.head, a.s_size);
		sort(a, b);
		free(a.begin_p);
		free(b.begin_p);
	}
	return (0);
}