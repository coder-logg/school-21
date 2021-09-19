#include "philo.h"

void	free_memory(t_philo *philos)
{
	if (philos != NULL && philos->data != NULL && philos->data->input != NULL)
	{
		check_err(sem_close(philos->data->forks), SEM_CLOSE_ERROR);
		check_err(sem_close(philos->data->print_sem), SEM_CLOSE_ERROR);
		free(philos->data->input);
	}
	if (philos != NULL && philos->data != NULL)
		free(philos->data);
	if (philos != NULL)
		free(philos);
}

static void	wait_death(t_philo *philos)
{
	int	st;
	int	i;
	int	count;

	st = 0;
	i = 0;
	count = 0;
	while (i++ < (int)philos->data->input->philos_nbr)
	{
		waitpid(-1, &st, 0);
		st = WEXITSTATUS(st);
		if (st == ALL_EATEN && ++count == (int)philos->data->input->philos_nbr)
		{
//			sem_wait(philos->data->print_sem);
			break ;
		}
		if (st == DEAD)
		{
			i = 0;
			while (i < (int)philos->data->input->philos_nbr)
				kill(philos[i++].pid, SIGKILL);
			break ;
		}
	}
}

void	finish(t_philo *philos)
{
	wait_death(philos);
	free_memory(philos);
}
