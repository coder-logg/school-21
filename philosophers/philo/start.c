#include "philo.h"

static int	init_sys(t_pdata *data)
{
	int	i;

	i = 0;
	data->forks = ft_calloc(data->input->philos_nbr, sizeof(pthread_mutex_t));
	if (data->forks == NULL)
		return (MALLOC_ERROR);
	while (i < (int)data->input->philos_nbr)
	{
		if (pthread_mutex_init(data->forks + i++, NULL))
			return (MUTEX_INIT_ERROR);
	}
	data->philos = ft_calloc(data->input->philos_nbr, sizeof(*data->philos));
	if (data->philos == NULL)
		return (MALLOC_ERROR);
	if (pthread_mutex_init(&(data->msg_mutex), NULL))
		return (MUTEX_INIT_ERROR);
	return (0);
}

static void	init_philos(t_pdata *data)
{
	int	i;

	i = 0;
	while (i < (int)data->input->philos_nbr)
	{
		memset(data->philos + i, 0, sizeof(*data->philos));
		data->philos[i].msg_mutex = &(data->msg_mutex);
		data->philos[i].philo_id = i + 1;
		data->philos[i].left_fork = data->forks + i;
		data->philos[i].input = data->input;
		data->philos[i].state = LIVE;
		data->philos[i].err = &data->err;
		if (i != (int)data->input->philos_nbr - 1)
			data->philos[i].right_fork = data->forks + i + 1;
		else
			data->philos[i].right_fork = data->forks;
		i++;
	}
}

int	init_pdata(t_pdata *data, int argc, char **argv)
{
	int	tmp;

	data->input = ft_calloc(1, sizeof(*data->input));
	if (data->input == NULL)
		return (MALLOC_ERROR);
	data->input->philos_nbr = ft_atoi(argv[0]);
	data->input->time_to_die = ft_atoi(argv[1]);
	data->input->time_to_eat = ft_atoi(argv[2]);
	data->input->time_to_sleep = ft_atoi(argv[3]);
	data->input->times_eat = -1;
	if (argc == 5)
		data->input->times_eat = ft_atoi(argv[4]);
	if (data->input->times_eat == 0)
		return (INPUT_DATA_ERROR);
	data->err = 0;
	tmp = init_sys(data);
	if (tmp)
		return (tmp);
	init_philos(data);
	return (0);
}

int	create_threads(t_pdata *data)
{
	int				i;
	unsigned long	time;

	i = 0;
	time = get_time();
	while (i < (int)data->input->philos_nbr)
	{
		data->philos[i].birth_time = time;
		if (pthread_create(&data->philos[i].thread_id, NULL, life,
				data->philos + i))
			return (PTHREAD_CREATE_ERROR);
		i++;
	}
	return (0);
}
