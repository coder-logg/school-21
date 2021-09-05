#include "philo.h"

int	main(int argc, char **argv)
{
	t_pdata	data;

	argc--;
	argv++;
	if (argc != 4 && argc != 5)
	{
		print_err_msg(INPUT_FORMAT_ERROR);
		return (1);
	}
	if (!check_args(argc, argv))
		return (1);
	if (print_err_msg(init_pdata(&data, argc, argv)) != 0)
		return (1);
	if (print_err_msg(create_threads(&data)) != 0)
		return (1);
	finish(&data);
	return (0);
}
