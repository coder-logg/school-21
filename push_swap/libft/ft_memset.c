#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	while (len-- > 0)
		*(char *)(s + len) = (char)c;
	return (s);
}

void	*ft_setmem(void *s, int c, size_t len)
{
	while (len-- > 0)
		*(char *)(s++) = (char)c;
	return (s);
}
