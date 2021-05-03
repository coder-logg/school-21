#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = malloc(len + 1);
	if (res != NULL)
		ft_strlcpy(res, s1, len + 1);
	return (res);
}
