#include <errno.h>
#include "philo.h"

static t_pdata	*create_data(int argc, char **argv, t_pdata **data)
{
	*data = NULL;
	*data = ft_calloc(1, sizeof(**data));
	if (*data == NULL)
		ft_error(MALLOC_ERROR, NULL);
	(*data)->input = NULL;
	(*data)->input = ft_calloc(1, sizeof(*(*data)->input));
	if ((*data)->input == NULL)
		ft_error(MALLOC_ERROR, NULL);
	(*data)->input->philos_nbr = ft_atoi(argv[0]);
	(*data)->input->time_to_die = ft_atoi(argv[1]);
	(*data)->input->time_to_eat = ft_atoi(argv[2]);
	(*data)->input->time_to_sleep = ft_atoi(argv[3]);
	(*data)->input->times_eat = -1;
	if (argc == 5)
		(*data)->input->times_eat = ft_atoi(argv[4]);
	sem_unlink("forks");
	sem_unlink("print_sem");
	(*data)->forks = sem_open("forks", O_CREAT, S_IRWXU,
			(*data)->input->philos_nbr);
	if ((*data)->forks == SEM_FAILED)
		ft_error(SEM_OPEN_ERROR, NULL);
	(*data)->print_sem = sem_open("print_sem", O_CREAT, S_IRWXU, 1);
	if ((*data)->print_sem == SEM_FAILED)
		ft_error(SEM_OPEN_ERROR, NULL);
	return (*data);
}

void	init(t_philo **philos, int argc, char **argv)
{
	t_pdata	*data;
	int		i;

	i = 0;
	create_data(argc, argv, &data);
	*philos = NULL;
	*philos = ft_calloc(data->input->philos_nbr, sizeof(**philos));
	if (*philos == NULL)
		ft_error(MALLOC_ERROR, NULL);
	while (i < (int)data->input->philos_nbr)
	{
		memset(*philos + i, 0, sizeof(**philos));
		(*philos)[i].data = data;
		(*philos)[i].philo_id = i + 1;
//		(*philos)[i].last_eat_time = 0;
		i++;
	}
}

void	create_processes(t_philo *philos)
{
	int	i;

	i = 0;
	philos->data->start_time = get_time();
	while (i < (int)philos->data->input->philos_nbr)
	{
		philos[i].pid = fork();
		if (philos[i].pid == -1)
			ft_error(PROCESS_CREATE_ERROR, NULL);
		else if (philos[i].pid == 0)
			life(philos + i);
		i++;
	}
}
