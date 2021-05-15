#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (res != NULL)
	{
		ft_memmove(res, s1, s1_len);
		ft_memmove(res + s1_len, s2, s2_len);
		res[s1_len + s2_len] = 0;
		free((void *)s1);
	}
	return (res);
}

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

void	*ft_memset(void *s, int c, size_t len)
{
	while (len-- > 0)
		*(char *)(s + len) = (char)c;
	return (s);
}
