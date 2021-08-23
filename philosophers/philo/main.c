#include "philo.h"

void	init_philos(t_pdata *data)
{
	int	i;

	i = 0;
	data->forks = ft_calloc(data->input->philos_nbr,  sizeof(*data->forks));
	while (i < data->input->philos_nbr)
	{
		pthread_mutex_init(data->forks + i, NULL);
		i++;
	}
	data->philos = ft_calloc(data->input->philos_nbr,  sizeof(*data->philos));
	pthread_mutex_init(&data->msg_mutex, NULL);
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

void	create_threads(t_pdata *data)
{
	int	i;

	i = 0;
	while (i < data->input->philos_nbr)
	{
		data->philos[i].birth_time = get_time();
		pthread_create(&data->philos[i].thread_id, NULL, life, data->philos + i);
//		printf("%d left_fork %p, right_fork %p\n", data->philos[i].philo_id, data->philos[i].left_fork, data->philos[i].right_fork);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < data->input->philos_nbr)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}

void	wait_finish(t_pdata *data)
{
	int		i;
	while (1)
	{
		i = 0;
		while (i < data->input->philos_nbr)
		{
			if (data->philos[i].state == DEAD)
				return ;
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	t_pdata data;

	argc--;
	argv++;
	if (argc != 4 && argc != 5)
	{
		printf(ERR_MSG);
		return (1);
	}
	if (!check_args(argc, argv))
		return (1);
	data.input = ft_calloc(1 ,  sizeof(*data.input));
	data.input->philos_nbr = ft_atoi(argv[0]);
	data.input->time_to_die = ft_atoi(argv[1]);
	data.input->time_to_eat = ft_atoi(argv[2]);
	data.input->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 5)
		data.input->times_eat = ft_atoi(argv[4]);
	else
		data.input->times_eat = 0;
	init_philos(&data);
	create_threads(&data);
	wait_finish(&data);
	return (0);
}