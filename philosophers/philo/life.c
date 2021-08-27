#include "philo.h"

void	take_fork_msg(t_philosopher *phil)
{
	pthread_mutex_lock(phil->msg_mutex);
	printf("\x1b[32m%llu %d has taken fork\n\x1b[0m", get_time() - phil->birth_time, phil->philo_id);
	pthread_mutex_unlock(phil->msg_mutex);
}

void	print_msg(t_philosopher *phil)
{
	pthread_mutex_lock(phil->msg_mutex);
	if (phil->state == EATING)
		printf("\x1b[92m%llu %d is eating\n\x1b[0m", get_time() - phil->birth_time, phil->philo_id);
	if (phil->state == SLEEPING)
		printf("\x1b[94m%llu %d is sleeping\n\x1b[0m", get_time() - phil->birth_time, phil->philo_id);
	if (phil->state == THINKING)
		printf("\x1b[93m%llu %d is thinking\n\x1b[0m", get_time() - phil->birth_time, phil->philo_id);
	if (phil->state == DEAD)
	{
		printf("\x1b[91m%llu %d died\n\x1b[0m", get_time() - phil->birth_time, phil->philo_id);
	}
//	if (phil->state != DEAD)
//	{
		pthread_mutex_unlock(phil->msg_mutex);
//	}
}


void	eat(t_philosopher *phil)
{
	pthread_mutex_lock(phil->left_fork);
	take_fork_msg(phil);
	pthread_mutex_lock(phil->right_fork);
	take_fork_msg(phil);
	phil->state = EATING;
	print_msg(phil);
	phil->last_eat_time = get_time();
	go_sleep(phil->input->time_to_eat, phil);
	pthread_mutex_unlock(phil->left_fork);
	pthread_mutex_unlock(phil->right_fork);
}

void	*life(void *arg)
{
	t_philosopher *phil;

	phil = (t_philosopher *)arg;
	pthread_detach(phil->thread_id);
	if (phil->philo_id % 2)
		usleep(1000);
	while (phil->state != DEAD)
	{
		eat(phil);
		phil->state = SLEEPING;
		print_msg(phil);
		go_sleep(phil->input->time_to_sleep, phil);
		phil->state = THINKING;
		print_msg(phil);
	}
	return (NULL);
}
