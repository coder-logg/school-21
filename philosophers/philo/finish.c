#include "philo.h"

void	free_memory(t_pdata *data)
{
	free(data->input);
	free(data->forks);
	free(data->philos);
	// todo destroy mutexes
}

void	wait_death(t_pdata *data)
{
	int		i;
	int		counter;

	while (1)
	{
		i = 0;
		counter = 0;
		while (i < (int)data->input->philos_nbr)
		{
			if (data->philos[i].state == DEAD)
			{
//				pthread_mutex_lock(&data->msg_mutex);
				print_status(data->philos + i, "died", "\x1b[31m", DEAD);
				return ;
			}
			if (data->philos[i].state == ALL_EATEN)
				counter++;
			i++;
		}
		if (counter == (int)data->input->philos_nbr)
			break ;
	}
}

void	finish(t_pdata *data)
{
	wait_death(data);
	free_memory(data);
}