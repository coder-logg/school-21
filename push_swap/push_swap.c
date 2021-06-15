#include "push_swap.h"

void	error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

char	check_digits(char *str)
{
	unsigned int	i;

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

void	check_duplicates(t_snode arr[], unsigned int arr_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < arr_size - 1)
	{
		j = 0;
		while (j++ < arr_size - 1)
		{
			if (i == j)
				continue ;
			if (arr[i].val == arr[j].val)
				error("Error\n");
		}
		i++;
	}
}

// начало стека - левый конец массива, конец стека - правый конец массива
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		arr[2];

	if (argc > 1)
	{
		argv++;
		argc--;
		i = 0;
		if_one_arg(argc, &argv, &i);
		if (i > 0)
			argc = i;
		arr[0] = argc;
		arr[1] = i;
		fill_ab(arr, &argv, &a, &b);
		check_duplicates(a.head, a.size);
		sort(a, b);
		freee(argv, &a, &b, i);
	}
	else
		error("Pass at least one argument to the program.\n");
	return (0);
}
