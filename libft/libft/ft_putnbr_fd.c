#include "libft.h"

static int	ten_in_pwr(int c)
{
	if (c == 1)
		return (10);
	if (c == 0)
		return (1);
	return (ten_in_pwr(c - 1) * 10);
}

static int	zero_ornegative(int n, int fd, unsigned int *un)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	if (n < 0)
	{
		*un = ~(*un);
		(*un)++;
		write(fd, "-", 1);
		return (-1);
	}
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;
	char			i;
	unsigned int	tmp_un;

	un = n;
	c = 0;
	i = 0;
	if (!zero_ornegative(n, fd, &un) || fd < 0)
		return ;
	tmp_un = un;
	while (un > 0)
	{
		i++;
		un /= 10;
	}
	while (i-- > 0)
	{
		c = tmp_un / ten_in_pwr(i) + '0';
		write(fd, &c, 1);
		tmp_un = tmp_un % ten_in_pwr(i);
	}
}
