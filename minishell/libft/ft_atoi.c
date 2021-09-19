#include "libft.h"

long	make_nbr(const char *s, char is_positive)
{
	unsigned long	res;
	unsigned long	max_ul;
	size_t			i;

	i = 0;
	res = 0;
	max_ul = 0 - 1;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		if (res >= max_ul / 10)
		{
			if (is_positive == 1)
				return (-1);
			return (0);
		}
		res = res * 10 + s[i] - '0';
		i++;
	}
	return ((res * is_positive));
}

long	ft_atoi(const char *str)
{
	size_t	i;
	char	is_positive;

	is_positive = 1;
	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'
			|| (str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				if (str[i] == '-')
					is_positive = -1;
			}
			else
				return (0);
		}
		if (str[i] >= '0' && str[i] <= '9')
			return (make_nbr(str + i, is_positive));
		i++;
	}
	return (0);
}
