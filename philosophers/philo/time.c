#include "philo.h"

long long int  get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000 + time.tv_usec) / 1000);
}

void    go_sleep(unsigned long int time, t_philosopher *phil)
{
	unsigned long int  new_time;

	new_time = get_time() + time;
	while (get_time() < new_time)
	{
		if (get_time() - phil->last_eat_time >= phil->input->time_to_die)
		{
			phil->state = DEAD;
			pthread_mutex_lock(phil->msg_mutex);
			break ;
		}
		usleep(50);
	}
}