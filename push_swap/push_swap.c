#include "push_swap.h"

int main(int argc, char **argv)
{
	int				a[argc - 1];
	unsigned int	i;
	i = 1;
	while (i < argc)
	{
		a[i] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}