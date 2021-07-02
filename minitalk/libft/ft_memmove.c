#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	flag;
	char	*start_src;
	char	*start_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	flag = 1;
	start_src = (char *)src;
	start_dst = (char *)dst;
	if (src < dst)
	{
		flag = -1;
		start_src = start_src + len - 1;
		start_dst = start_dst + len - 1;
	}
	while (0 < len--)
	{
		*(start_dst + i * flag) = *(start_src + i * flag);
		i++;
	}
	return (dst);
}
