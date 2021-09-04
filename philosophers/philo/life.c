#include <errno.h>
#include <string.h>
#include "philo.h"

void print_status(t_philosopher *phil, const char *str, const char *color,
				  int state)
{
//	pthread_mutex_lock(phil->msg_mutex);
//	if (is_dead)
//		phil->state = DEAD;
	if (pthread_mutex_lock(phil->msg_mutex))
		printf("lock %s\n", strerror(errno));
	phil->state = state;
//	if (phil->state == DEAD)
//	{
////		usleep(50);
////		printf("%d dead\n",  phil->philo_id);
//	}
	printf("%s%lu	%d	%s\n\x1b[0m", color, get_time() - phil->birth_time, phil->philo_id, str);
	if (phil->state != DEAD)
	{
		if (pthread_mutex_unlock(phil->msg_mutex))
			printf("unlock %s\n", strerror(errno));
	}
}

void	eat(t_philosopher *phil)
{
	if (phil->philo_id % 2)
		pthread_mutex_lock(phil->left_fork);
	else
		pthread_mutex_lock(phil->right_fork);
	print_status(phil, "has taken fork", "\x1b[32m", LIVE);
	if (phil->philo_id % 2)
		pthread_mutex_lock(phil->right_fork);
	else
		pthread_mutex_lock(phil->left_fork);
	print_status(phil, "has taken fork", "\x1b[32m", LIVE);
	print_status(phil, "is eating", "\x1b[92m", LIVE);
	phil->last_eat_time = get_time();
	phil->eat_counter++;
	go_sleep(phil->input->time_to_eat, phil);
	if (phil->state == DEAD)
		return ;
	if (phil->philo_id % 2)
		pthread_mutex_unlock(phil->left_fork);
	else
		pthread_mutex_unlock(phil->right_fork);
	if (phil->philo_id % 2)
		pthread_mutex_unlock(phil->right_fork);
	else
		pthread_mutex_unlock(phil->left_fork);
}

void	*life(void *arg)
{
	t_philosopher *phil;

	phil = (t_philosopher *)arg;
	pthread_detach(phil->thread_id);
	while (1)
	{
		eat(phil);
		if (phil->state == DEAD)
			break ;
		if (phil->eat_counter == phil->input->times_eat)
		{
			phil->state = ALL_EATEN;
			break ;
		}
		print_status(phil, "is sleeping", "\x1b[94m", LIVE);
		go_sleep(phil->input->time_to_sleep, phil);
		if (phil->state == DEAD)
			break ;
		print_status(phil, "is thinking", "\x1b[93m", LIVE);
	}
	return (NULL);
}
