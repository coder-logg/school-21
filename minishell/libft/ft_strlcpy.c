#include "libft.h"

size_t	ft_strlcpy (char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	a;

	i = 0;
	a = 0;
	if (dst == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len == size)
		a++;
	while (i < size - 1 && i < src_len + a)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (src_len);
}
