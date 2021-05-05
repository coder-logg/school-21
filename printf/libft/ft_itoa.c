#include "libft.h"
#include <string.h>

static int	digit_number(int n, unsigned int *tmp_un)
{
	unsigned int	un;
	int				i;

	if (n == 0)
	{
		*tmp_un = 0;
		return (1);
	}
	un = n;
	i = 0;
	if (n < 0)
	{
		un = ~un;
		un++;
		i++;
	}
	(*tmp_un) = un;
	while (un > 0)
	{
		i++;
		un /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	tmp_un;
	int				dnbr;

	dnbr = digit_number(n, &tmp_un);
	res = (char *)malloc(sizeof(char) * (dnbr + 1));
	if (res != NULL)
	{
		res[dnbr] = 0;
		if (n < 0)
			res[0] = '-';
		else
			res[0] = 0;
		while (dnbr > 0 + (res[0] == '-'))
		{
			dnbr--;
			res[dnbr] = tmp_un % 10 + '0';
			tmp_un /= 10;
		}
	}
	return (res);
}
