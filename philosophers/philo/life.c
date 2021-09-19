#include "philo.h"

void	checkerr(t_philo *phil, int function_res, t_errors err_code)
{
	if (function_res)
		*phil->err = err_code;
}

void	*check_state(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;
	while (1)
	{
		usleep(100);
		if (phil->last_eat_time != 0 && get_time() > phil->last_eat_time
			&& get_time() - phil->last_eat_time > phil->input->time_to_die
			&& phil->state != EATING)
		{
			print_state(phil, "died", "\x1b[31m", DEAD);
			return (NULL);
		}
		if (phil->eat_counter == phil->input->times_eat)
		{
			pthread_mutex_lock(&phil->chg_state);
			phil->state = ALL_EATEN;
			return (NULL);
		}
	}
}

void	eat(t_philo *phil)
{
	if (phil->philo_id % 2)
	{
		usleep(100);
		checkerr(phil, pthread_mutex_lock(phil->right_fork), LOCK_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m", LIVE);
		checkerr(phil, pthread_mutex_lock(phil->left_fork), LOCK_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m", LIVE);
	}
	else
	{
		checkerr(phil, pthread_mutex_lock(phil->left_fork), LOCK_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m", LIVE);
		checkerr(phil, pthread_mutex_lock(phil->right_fork), LOCK_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m", LIVE);
	}
	print_state(phil, "is eating", "\x1b[92m", EATING);
	phil->last_eat_time = get_time();
	phil->eat_counter++;
	go_sleep(phil->input->time_to_eat);
	checkerr(phil, pthread_mutex_unlock(phil->right_fork), UNLOCK_ERROR);
	checkerr(phil, pthread_mutex_unlock(phil->left_fork), UNLOCK_ERROR);
	pthread_mutex_lock(&phil->chg_state);
	phil->state = LIVE;
	pthread_mutex_unlock(&phil->chg_state);
}

void	*life(void *arg)
{
	t_philo		*phil;
	pthread_t	thread_to_check;

	phil = (t_philo *)arg;
	if (phil->input->philos_nbr == 1)
	{
		checkerr(phil, pthread_mutex_lock(phil->right_fork), LOCK_ERROR);
		print_state(phil, "has taken fork", "\x1b[32m", LIVE);
		go_sleep(phil->input->time_to_die);
		print_state(phil, "died", "\x1b[31m", DEAD);
		return (NULL);
	}
	pthread_create(&thread_to_check, NULL, check_state, arg);
	pthread_mutex_init(&phil->chg_state, NULL);
	pthread_detach(thread_to_check);
	pthread_detach(phil->thread_id);
	while (phil->state == LIVE)
	{
		eat(phil);
		print_state(phil, "is sleeping", "\x1b[94m", LIVE);
		go_sleep(phil->input->time_to_sleep);
		print_state(phil, "is thinking", "\x1b[93m", LIVE);
	}
	return (NULL);
}
