#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_arg(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*(arg++)))
			return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (!(check_arg(argv[0]) && check_arg(argv[1])
			&& check_arg(argv[2]) && check_arg(argv[3]))
		|| (argc == 5 && !check_arg(argv[4])))
	{
		print_err_msg(INPUT_DATA_ERROR);
		return (0);
	}
	return (1);
}
