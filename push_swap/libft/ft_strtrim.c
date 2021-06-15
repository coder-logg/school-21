#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	front = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[front]) != NULL && s1[front])
		front++;
	while (ft_strchr(set, s1[end]) != NULL && s1 + front != s1 + end)
		end--;
	res = (char *)malloc(sizeof(char) * (end - front + 2));
	if (res != NULL)
		ft_strlcpy(res, s1 + front, end - front + 2);
	return (res);
}
