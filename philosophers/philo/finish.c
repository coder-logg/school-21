#include "philo.h"

void	free_memory(t_pdata *data)
{
	free(data->input);
	free(data->forks);
	free(data->philos);
}

int	check_death(t_pdata *data)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (i < (int)data->input->philos_nbr)
	{
		if (data->philos[i].state == DEAD)
		{
			print_state(data->philos + i, "died", "\x1b[31m", DEAD);
			return (1);
		}
		if (data->philos[i].state == ALL_EATEN)
			counter++;
		if (data->err != 0)
		{
			pthread_mutex_lock(&data->msg_mutex);
			print_err_msg(data->err);
			return (1);
		}
		i++;
	}
	if (counter == (int)data->input->philos_nbr)
		return (1);
	return (0);
}

void	wait_death(t_pdata *data)
{
	while (1)
	{
		if (check_death(data))
			return ;
	}
}

void	finish(t_pdata *data)
{
	wait_death(data);
	free_memory(data);
}
