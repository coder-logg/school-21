#include "philo.h"

void	print_state(t_philo *phil, const char *str, const char *clr, int state)
{
	if (*phil->err == 0)
	{
		pthread_mutex_lock(phil->msg_mutex);
		phil->state = state;
		printf("%s%lu	%d	%s\n\x1b[0m", clr,
			   get_time() - phil->birth_time, phil->philo_id, str);
		if (phil->state != DEAD)
			pthread_mutex_unlock(phil->msg_mutex);
	}
}

int	print_err_msg(t_errors err)
{
	if (err == MALLOC_ERROR)
		printf("Malloc error.\n");
	if (err == INPUT_DATA_ERROR)
		printf("Error is in input data. "
			   "All arguments should be integer numbers.\n");
	if (err == MUTEX_INIT_ERROR)
		printf("Mutex error.\n");
	if (err == INPUT_FORMAT_ERROR)
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			   " time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	if (err == PTHREAD_CREATE_ERROR)
		printf("Thread creation error.\n");
	if (err == UNLOCK_ERROR)
		printf("Mutex unlock error.\n");
	if (err == LOCK_ERROR)
		printf("Mutex lock error.\n");
	return (err);
}
