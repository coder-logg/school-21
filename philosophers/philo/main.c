#include "philo.h"

int	print_err_msg(t_errors err)
{
	if (err == MALLOC_ERROR)
		printf("Malloc error.\n");
	if (err == INPUT_DATA_ERROR)
		printf("Error is in input data. All arguments should be integer numbers.\n");
	if (err == MUTEX_INIT_ERROR)
		printf("Mutex error.\n");
	if (err == INPUT_FORMAT_ERROR)
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			   " time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	if (err == PTHREAD_CREATE_ERROR)
		printf("Thread creation error.\n");
	return (err);
}



int	main(int argc, char **argv)
{
	t_pdata data;

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