#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

void	for_each_chr_in_str(char *str, char ( *f)(char))
{
	if (str == NULL || f == NULL)
		return ;
	while (*str)
	{
		*str = f(*str);
		str++;
	}
}
