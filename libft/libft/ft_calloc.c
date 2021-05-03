#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (res != NULL)
		ft_memset(res, 0, size * nmemb);
	return (res);
}
