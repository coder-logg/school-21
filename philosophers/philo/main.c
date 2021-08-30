#include "philo.h"

void	free_memory(t_pdata *data)
{
	free(data->input);
	free(data->forks);
	free(data->philos);
	// todo destroy mutexes
}

void	print_err_msg(t_errors err)
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
}

void	wait_death(t_pdata *data)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < data->input->philos_nbr)
		{
			if (data->philos[i].state == DEAD)
			{
				printf("\x1b[91m%llu %d died\n\x1b[0m",
					get_time() - data->philos[i].birth_time,
					data->philos[i].philo_id);
				return ;
			}
			i++;
		}
	}
}

void	finish(t_pdata *data)
{
	wait_death(data);
	free_memory(data);
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
	init_pdata(&data, argc, argv);
	create_threads(&data);
	finish(&data);
	return (0);
}