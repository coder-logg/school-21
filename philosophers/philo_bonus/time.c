#include "philo.h"

unsigned long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	go_sleep(unsigned long time)
{
	unsigned long int	new_time;

	new_time = get_time() + time;
	while (get_time() < new_time)
		usleep(50);
}
