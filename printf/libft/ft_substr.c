#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	res_len;

	if (s == NULL)
		return (NULL);
	res_len = ft_strlen(s + start);
	if (ft_strlen(s) <= start)
		res_len = 0;
	if (res_len > len)
		res_len = len;
	res = malloc(res_len + 1);
	if (res != NULL)
		ft_strlcpy(res, s + start, res_len + 1);
	return (res);
}
