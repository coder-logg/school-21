#include <errno.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;

	argc--;
	argv++;
	if (argc != 4 && argc != 5)
		ft_error(INPUT_FORMAT_ERROR, NULL);
	check_args(argc, argv);
	init(&philos, argc, argv);
	ft_error(0, philos);
	create_processes(philos);
	finish(philos);
	return (0);
}
