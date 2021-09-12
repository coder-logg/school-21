#include "philo.h"

void	*check_state(void *ptr)
{
	t_philo			*phil;
	unsigned long	time;

	phil = (t_philo *)ptr;
	while (1)
	{
		time = get_time();
		if (time - phil->last_eat_time >= phil->data->input->time_to_die
			&& time > phil->last_eat_time)
		{
			check_err(sem_wait(phil->data->print_sem), SEM_WAIT_ERROR);
			printf("%s %lu	%d	%s\n\x1b[0m", "\x1b[91m",
				   get_time() - phil->data->start_time, phil->philo_id, "died");
			exit(DEAD);
		}
	}
}

void	eat(t_philo *phil)
{
	check_err(sem_wait(phil->data->forks), SEM_WAIT_ERROR);
	print_state(phil, "has taken fork", "\x1b[32m");
	if (phil->data->input->philos_nbr != 1)
	{
		check_err(sem_wait(phil->data->forks), SEM_WAIT_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m");
		phil->last_eat_time = get_time();
		print_state(phil, "is eating", "\x1b[92m");
		go_sleep(phil->data->input->time_to_eat);
		phil->eat_counter++;
		check_err(sem_post(phil->data->forks), SEM_POST_ERROR);
	}
	else
		go_sleep(phil->data->input->time_to_die);
	check_err(sem_post(phil->data->forks), SEM_POST_ERROR);
}

void	*life(void *arg)
{
	t_philo		*phil;
	pthread_t	check_death_thread;

	phil = (t_philo *)arg;
	if (phil->philo_id % 2)
		usleep(100);
	phil->last_eat_time = get_time();
	check_err(pthread_create(&check_death_thread, NULL, check_state, phil),
		PTHREAD_CREATE_ERROR);
	check_err(pthread_detach(check_death_thread), PTHREAD_DETACH_ERROR);
	while (1)
	{
		eat(phil);
		if (phil->data->input->times_eat
			&& phil->eat_counter == phil->data->input->times_eat)
			exit(ALL_EATEN);
		print_state(phil, "is sleeping", "\x1b[94m");
		go_sleep(phil->data->input->time_to_sleep);
		print_state(phil, "is thinking", "\x1b[93m");
	}
}
