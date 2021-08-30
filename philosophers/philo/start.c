#include "philo.h"

int	check_err(void *ptr, t_errors maybe_err)
{
	if (maybe_err == MUTEX_INIT_ERROR)
	{
		print_err_msg(maybe_err);
		return ((long int)ptr);
	}
	if (maybe_err == MALLOC_ERROR && ptr == NULL)
	{
		print_err_msg(maybe_err);
		return (-1);
	}
	return (0);
}

static int	init_sys(t_pdata *data)
{
	int	i;

	i = 0;


	data->forks = ft_calloc(data->input->philos_nbr,  sizeof(pthread_mutex_t));
	if (check_err(data->forks, MALLOC_ERROR))
		return (-1);
    pthread_mutex_init(data->forks + i++, NULL);
//	while (i < data->input->philos_nbr)
//	{
//		if (check_err((void *) pthread_mutex_init(data->forks + i++, NULL),
//					  MUTEX_INIT_ERROR))
//			return (-1);
//	}
	data->philos = ft_calloc(data->input->philos_nbr, sizeof(*data->philos));
//	if (check_err(data->philos, MALLOC_ERROR))
//		return (-1);
    pthread_mutex_init(&data->msg_mutex, NULL);
//	if (check_err((void *) pthread_mutex_init(&data->msg_mutex, NULL),
//				  MUTEX_INIT_ERROR))
//		return (-1);
    return (0);
}

static int	init_philos(t_pdata *data)
{
	int	i;


	i = 0;
	while (i < data->input->philos_nbr)
	{
		memset(data->philos + i, 0, sizeof(*data->philos));
		data->philos[i].msg_mutex = &data->msg_mutex;
		data->philos[i].philo_id = i + 1;
		data->philos[i].left_fork = data->forks + i;
		data->philos[i].input = data->input;
		data->philos[i].last_eat_time = get_time();
		if (i != data->input->philos_nbr - 1)
			data->philos[i].right_fork = data->forks + i + 1;
		else
			data->philos[i].right_fork = data->forks;
		i++;
	}
}

int init_pdata(t_pdata *data, int argc, char **argv)
{
    data->input = ft_calloc(1 ,  sizeof(*data->input));
	if (check_err(data->input, MALLOC_ERROR))
		return (-1);
	data->input->philos_nbr = ft_atoi(argv[0]);
	data->input->time_to_die = ft_atoi(argv[1]);
	data->input->time_to_eat = ft_atoi(argv[2]);
	data->input->time_to_sleep = ft_atoi(argv[3]);
	data->input->times_eat = 0;
	if (argc == 5)
		data->input->times_eat = ft_atoi(argv[4]);
    init_sys(data);
	init_philos(data);
	return(0);
}

void	create_threads(t_pdata *data)
{
	int	i;

	i = 0;
	long long int time = get_time();
	while (i < data->input->philos_nbr)
	{
		data->philos[i].birth_time = time;
		pthread_create(&data->philos[i].thread_id, NULL, life, data->philos + i);
		usleep(100);
		i++;
	}
}