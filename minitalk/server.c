#include "minitalk.h"

void	print_msg(int sig)
{
	static unsigned char	chr;
	static unsigned int		i;
	char					bit;

	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	if (i == 8)
	{
		i = 0;
		write(1, &chr, 1);
		chr = 0;
	}
	else
		chr |= bit << i++;
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, print_msg);
	signal(SIGUSR2, print_msg);
	while (1)
		pause();
	return (0);
}
