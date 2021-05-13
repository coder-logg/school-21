#include "get_next_line.h"
#include <stdio.h>

char* find_str_start_end(char* str, char direction)
{
	while (*str)
		str += direction;
	str += - direction;
	return str;
}
int	get_next_line(int fd, char **line)
{
	size_t		read_ret;
	static char	buf[BUFFER_SIZE + 1];
	char		*nl_chr_pos;

	if (buf[0] != 0)
	{
		nl_chr_pos = ft_memchr(buf, '\n', BUFFER_SIZE);
		if (nl_chr_pos != NULL)
		{
			nl_chr_pos[0] = 0;
			free(*line);
			*line = NULL;
			*line = ft_strjoin(*line, find_str_start_end(nl_chr_pos - 1, -1));
			ft_memmove(buf, nl_chr_pos + 1, buf + BUFFER_SIZE - nl_chr_pos - 1);
			ft_memset(buf + (buf + BUFFER_SIZE - nl_chr_pos - 1), 0,
				BUFFER_SIZE - ((buf + BUFFER_SIZE - nl_chr_pos - 1)));
		}
		else
		{
			free(*line);
			*line = NULL;
			*line = ft_strjoin(*line, buf);
//			ft_memmove(buf, nl_chr_pos + 1, buf + BUFFER_SIZE - nl_chr_pos - 1);
			ft_memset(buf, 0, BUFFER_SIZE);
		}
		read_ret = 1;
	}
	else
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1 || line == NULL)
			return (-1);
		*line = NULL;
		buf[read_ret] = 0;
		nl_chr_pos = NULL;
		while (read_ret != 0 && nl_chr_pos == NULL)
		{
			nl_chr_pos = ft_strchr(buf, '\n');
			if (nl_chr_pos != NULL)
				nl_chr_pos[0] = 0;
			*line = ft_strjoin(*line, buf);
			if (ft_memchr(buf, '\n', BUFFER_SIZE) != NULL)
				break ;
			read_ret = read(fd, buf, BUFFER_SIZE);
			buf[read_ret] = 0;
		}
	}
	if (read_ret > 1)
		read_ret = 1;
	return (read_ret);
}

//#include <fcntl.h>
//int main()
//{
//	char *line;
//	int fd;
//	int gnl_ret = 0;
//
//	fd = open("/Users/tphlogis/Documents/My_projects/gnl/test_input.txt", O_RDWR);
//	gnl_ret = get_next_line(fd, &line);
//	while (gnl_ret != 0)
//	{
////		printf("%d\n", gnl_ret);
//		printf("%s\n", line);
//		gnl_ret = get_next_line(fd, &line);
//	}
//	close(fd);
//}
