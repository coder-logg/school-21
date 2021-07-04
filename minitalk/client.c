#include "minitalk.h"

char	check_digits(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 || i > 11)
			return (0);
		i++;
	}
	return (1);
}

void	error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	send_char(unsigned int pid, unsigned char c)
{
	unsigned int	i;
	unsigned char	bit;

	i = 0;
	while (i <= 8)
	{
		bit = c & 1;
		c >>= 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("bad pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("bad pid\n");
		}
		usleep(15);
		i++;
	}
}

void	send_message(unsigned int pid, char *message)
{
	usleep(10);
	while (*message)
		send_char(pid, *(message++));
}

int	main(int argc, char **argv)
{
	unsigned int	pid;

	pid = 0;
	if (argc != 3)
		error("usage: ./client [server-pid] [message]\n");
	if (check_digits(argv[1]))
		pid = ft_atoi(argv[1]);
	else
		error("pid should be a natural number\n");
	send_message(pid, argv[2]);
	return (0);
}
