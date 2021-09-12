#include "philo.h"

void	print_state(t_philo *phil, const char *str, const char *clr)
{
	check_err(sem_wait(phil->data->print_sem), SEM_WAIT_ERROR);
	printf("%s %lu	%d	%s\n\x1b[0m", clr,
		   get_time() - phil->data->start_time, phil->philo_id, str);
	check_err(sem_post(phil->data->print_sem), SEM_POST_ERROR);
}

void	print_err(t_errors err)
{
	if (err == MALLOC_ERROR)
		printf("Malloc error.\n");
	if ((int)err == SEM_OPEN_ERROR)
		printf("Sem open error.\n");
	if (err == INPUT_DATA_ERROR)
		printf("Error is in input data. "
			   "All arguments should be integer numbers.\n");
	if (err == INPUT_FORMAT_ERROR)
		printf("Usage: ./philo_bonus number_of_philosophers time_to_die"
			   " time_to_eat time_to_sleep"
			   " [number_of_times_each_philosopher_must_eat]\n");
	if (err == PTHREAD_CREATE_ERROR)
		printf("Thread creation error.\n");
	if (err == PTHREAD_DETACH_ERROR)
		printf("Thread detach error.\n");
	if (err == PROCESS_CREATE_ERROR)
		printf("Process creation error.\n");
	if (err == SEM_POST_ERROR)
		printf("Semaphore post error.\n");
	if (err == SEM_UNLINK_ERROR)
		printf("Semaphore unlink error.\n");
	if (err == SEM_WAIT_ERROR)
		printf("Semaphore wait error.\n");
	if (err == SEM_CLOSE_ERROR)
		printf("Semaphore close error.\n");
}

int	is_err(int err_code)
{
	if (MALLOC_ERROR == err_code
		|| err_code == SEM_OPEN_ERROR
		|| err_code == INPUT_DATA_ERROR
		|| err_code == INPUT_FORMAT_ERROR
		|| err_code == PROCESS_CREATE_ERROR
		|| err_code == PTHREAD_CREATE_ERROR
		|| err_code == SEM_WAIT_ERROR
		|| err_code == SEM_POST_ERROR
		|| err_code == SEM_UNLINK_ERROR
		|| err_code == SEM_CLOSE_ERROR)
		return (1);
	return (0);
}

void	ft_error(t_errors err, t_philo *philos)
{
	static t_philo	*phils;

	if (philos != NULL)
	{
		phils = philos;
		return ;
	}
	print_err(err);
	if (is_err(err))
	{
		free_memory(philos);
		exit(err);
	}
}
