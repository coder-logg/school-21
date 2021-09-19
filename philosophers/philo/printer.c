#include "philo.h"

void	print_state(t_philo *ph, const char *str, const char *clr, int state)
{
	if (*ph->err == 0)
	{
		checkerr(ph, pthread_mutex_lock(ph->msg_mutex), LOCK_ERROR);
		pthread_mutex_lock(&ph->chg_state);
		ph->state = state;
		if (ph->state != DEAD)
			pthread_mutex_unlock(&ph->chg_state);
		printf("%s%lu	%d	%s\n\x1b[0m", clr,
			   get_time() - ph->birth_time, ph->philo_id, str);
		if (ph->state != DEAD)
			checkerr(ph, pthread_mutex_unlock(ph->msg_mutex), UNLOCK_ERROR);
	}
}

int	print_err_msg(t_errors err)
{
	if (err == MALLOC_ERROR)
		printf("Malloc error.\n");
	if (err == INPUT_DATA_ERROR)
		printf("Error is in input data. "
			   "All arguments should be integer greater then zero.\n");
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
