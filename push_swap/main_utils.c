#include "push_swap.h"

t_stack	init_stack(unsigned int size)
{
	t_stack	res;

	res.size = size;
	res.begin_p = ft_calloc(size, sizeof(t_snode));
	res.head = res.begin_p + size;
	return (res);
}

void	free_splited_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	fill_ab(int arr[], char ***argv, t_stack *a, t_stack *b)
{
	int				i;
	long			tmp;

	(*b) = init_stack(arr[0]);
	(*a) = init_stack(arr[0]);
	(*a).head = (*a).begin_p;
	i = 0;
	while (i < arr[0])
	{
		if (!check_digits((*argv)[i]))
		{
			if (arr[1] > 0)
				free_splited_argv(*argv);
			error("Error\n");
		}
		tmp = ft_atoi((*argv)[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			if (arr[1] > 0)
				free_splited_argv(*argv);
			error("Error\n");
		}
		((*a).begin_p + i++)->val = tmp;
	}
}

void	if_one_arg(int argc, char ***argv, int *i)
{
	if (argc == 1)
	{
		if (!check_digits(*(*argv)) && ft_strchr(**argv, ' ') == NULL)
			error("Error\n");
		(*argv) = ft_split((*argv)[0], ' ');
		while ((*argv)[(*i)])
			(*i)++;
	}
}

void	freee(char **argv, t_stack *a, t_stack *b, int i)
{
	if (i > 0)
		free_splited_argv(argv);
	free(a->begin_p);
	free(b->begin_p);
}
