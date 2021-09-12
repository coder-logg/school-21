#include "philo.h"

void	checkerr(t_philo *phil, int mutex_res, t_errors err_code)
{
	if (mutex_res)
		*phil->err = err_code;
}

int	check_state(t_philo *phil)
{
	if (get_time() - phil->last_eat_time >= phil->input->time_to_die)
	{
		phil->state = DEAD;
		return (DEAD);
	}
	if (phil->eat_counter == phil->input->times_eat
		&& phil->input->philos_nbr != 1)
	{
		phil->state = ALL_EATEN;
		return (ALL_EATEN);
	}
	return (0);
}

void	eat(t_philo *phil)
{
	checkerr(phil, pthread_mutex_lock(phil->left_fork), LOCK_ERROR);
	print_state(phil, "has taken fork", "\x1b[32m", LIVE);
	if (phil->input->philos_nbr != 1)
	{
		checkerr(phil, pthread_mutex_lock(phil->right_fork), LOCK_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m", LIVE);
		print_state(phil, "is eating", "\x1b[92m", LIVE);
		phil->last_eat_time = get_time();
		phil->eat_counter++;
		go_sleep(phil->input->time_to_eat, phil);
		checkerr(phil, pthread_mutex_unlock(phil->right_fork), UNLOCK_ERROR);
	}
	else
		go_sleep(phil->input->time_to_die, phil);
	checkerr(phil, pthread_mutex_unlock(phil->left_fork), UNLOCK_ERROR);
}

void	*life(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;
	pthread_detach(phil->thread_id);
	if (phil->philo_id % 2)
		usleep(100);
	while (phil->state == LIVE)
	{
		eat(phil);
		if (check_state(phil))
			break ;
		print_state(phil, "is sleeping", "\x1b[94m", LIVE);
		go_sleep(phil->input->time_to_sleep, phil);
		if (phil->state != LIVE)
			break ;
		print_state(phil, "is thinking", "\x1b[93m", LIVE);
	}
	return (NULL);
}
