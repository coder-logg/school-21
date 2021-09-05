#include "philo.h"

unsigned long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	go_sleep(unsigned long int time, t_philo *phil)
{
	unsigned long int	new_time;

	new_time = get_time() + time;
	while (get_time() < new_time)
	{
		if (check_state(phil))
			return ;
		usleep(50);
	}
}
