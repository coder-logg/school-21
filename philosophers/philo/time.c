#include "philo.h"

unsigned long int  get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    go_sleep(unsigned long int time, t_philosopher *phil)
{
	unsigned long int  new_time;

	new_time = get_time() + time;
	while (get_time() < new_time)
	{
		if (get_time() - phil->last_eat_time > phil->input->time_to_die)
		{
			phil->state = DEAD;
//			print_status(phil, "died", "\x1b[31m", DEAD);
			return ;
		}
		usleep(50);
	}
}