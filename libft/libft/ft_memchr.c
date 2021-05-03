#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*res;
	size_t	i;

	i = 0;
	res = NULL;
	while (i < n && *(char *)(s + i) != (char)c)
		i++;
	if (i != n)
		res = (char *)(s + i);
	return (res);
}
