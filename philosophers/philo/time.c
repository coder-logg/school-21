#include "philo.h"

//unsigned long int get_time()
//{
//	struct timeval time;
//
//	gettimeofday(&time, DST_NONE);
//
//}


unsigned long int  get_time(void)
{
	struct timeval          time;
	unsigned long int        ret;

	if (gettimeofday(&time, NULL))
		return (0);
	ret = time.tv_sec * 1000 + time.tv_usec * 0.001;
	return (ret);
}

void    go_sleep(unsigned long int time_period, t_philosopher *phil)
{
	unsigned long int  new_time;

	new_time = get_time() + time_period;
	while (get_time() < new_time)
	{
		if (get_time() - phil->last_eat_time>=phil->input->time_to_eat)
		{
			phil->state = DEAD;
			print_msg(phil);
			break ;
		}
		usleep(10);
	}
}