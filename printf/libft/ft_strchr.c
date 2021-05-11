#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*find_chrs_in_str(const char *s, char *chrs)
{
	char	*ptr;

	while (*(s++))
	{
		ptr = ft_strchr(chrs, *s);
		if (ptr != NULL)
			return (ptr);
	}
	return (NULL);
}
