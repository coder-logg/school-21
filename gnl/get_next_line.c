#include "get_next_line.h"

int	gnl(char **line, char buf[], int i, char *nl)
{
	nl = ft_memchr(buf, '\n', BUFFER_SIZE);
	if (i == 0)
		free(*line);
	if (nl == NULL)
	{
		if (i == 0)
			*line = ft_strjoin(NULL, buf);
		else
			*line = ft_strjoin(*line, buf);
		ft_memset(buf, 0, BUFFER_SIZE);
		return (0);
	}
	else
	{
		nl[0] = 0;
		if (i == 0)
			*line = ft_strjoin(NULL, buf);
		else
			*line = ft_strjoin(*line, buf);
		ft_memmove(buf, nl + 1, buf + BUFFER_SIZE - nl - 1);
		ft_memset(buf + (buf + BUFFER_SIZE - nl - 1), 0,
			BUFFER_SIZE - ((buf + BUFFER_SIZE - nl - 1)));
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	int			rr;
	static char	buf[BUFFER_SIZE + 1];
	int			gnl_ret;
	int			i;

	if (line == NULL || read(fd, buf, 0) < 0 || BUFFER_SIZE < 0)
		return (-1);
	rr = 1;
	if (buf[0] == 0)
		rr = read(fd, buf, BUFFER_SIZE);
	*line = NULL;
	if (rr == 0)
	{
		*line = ft_memset(malloc(1), 0, 1);
		return (0);
	}
	i = 0;
	gnl_ret = 0;
	while (rr != 0 && gnl_ret != 1)
	{
		gnl_ret = gnl(line, buf, i++, ft_memchr(buf, '\n', BUFFER_SIZE));
		if (BUFFER_SIZE != ft_strlen(buf))
			rr = read(fd, buf + ft_strlen(buf), BUFFER_SIZE - ft_strlen(buf));
	}
	return (rr || gnl_ret);
}
