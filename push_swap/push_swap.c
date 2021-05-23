#include "push_swap.h"

void	error()
{
	write(1, "Error\n", 6);
	exit(1);
}

char	check_digits(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 || i > 11)
			return (1);
		i++;
	}
	return (0);
}

void	check_duplicates(int arr[],  unsigned int arr_size)
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
			if (arr[i] == arr[j])
				error();
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	unsigned int	i;
	long			tmp;
	t_stack			a;
	t_stack			b;

	if (argc > 1)
	{
		a.begin_p = ft_calloc(argc - 1, sizeof(int));
		b.begin_p = ft_calloc(argc - 1, sizeof(int));

		a.s_size = argc - 1;
		b.s_size = argc - 1;

		b.head = b.begin_p + argc - 1;
		a.head = a.begin_p;
		i = 0;
		while ((int)i < argc - 1)
		{
			if (check_digits(argv[i + 1]))
				error();
			tmp = ft_atoi(argv[i + 1]);
			if (tmp > 2147483647 || tmp < -2147483648)
				error();
			a.begin_p[i++] = tmp;
		}
		check_duplicates(a.head, a.s_size);
		sort(a, b);
		free(a.begin_p);
		free(b.begin_p);
	}
	return (0);
}