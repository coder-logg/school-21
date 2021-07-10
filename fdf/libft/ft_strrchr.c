char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		res = (char *)&s[i];
	return (res);
}
