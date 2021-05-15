#include "get_next_line.h"
#include <stdio.h>

char* find_str_start_end(char* str, char direction)
{
	if (!(*str))
		return (str);
	while (*str)
		str += direction;
	return (str);
}

char *shift_buf_to_nl(char* buf)
{
	char* nl_chr_pos;
	nl_chr_pos = ft_memchr(buf, '\n', BUFFER_SIZE);
	if (nl_chr_pos != NULL)
	{
		ft_memmove(buf, nl_chr_pos + 1, buf + BUFFER_SIZE - nl_chr_pos - 1);
		ft_memset(buf + (buf + BUFFER_SIZE - nl_chr_pos - 1), 0,
			BUFFER_SIZE - ((buf + BUFFER_SIZE - nl_chr_pos - 1)));
	}
	return (buf);
}

int get_next_line(int fd, char **line)
{
	int read_ret;
	int res;
	static char buf[BUFFER_SIZE + 1];
	char* nl_chr_pos;
	int i;

	if (buf[0] != 0)
	{
		read_ret = 1;
		i = 0;
		res = -1;
		while (read_ret != 0)
		{
			if (ft_memchr(buf, '\n', BUFFER_SIZE) == NULL)
			{
				res = 0;
				if (i == 0)
				{
					free(*line);
					*line = ft_strjoin(NULL, buf);
				}
				else
					*line = ft_strjoin(*line, buf);
				ft_memset(buf, 0, BUFFER_SIZE);
				read_ret = read(fd, buf, BUFFER_SIZE);
				i++;
			}
			else
			{
				res = 1;
				nl_chr_pos = ft_memchr(buf, '\n', BUFFER_SIZE);
				nl_chr_pos[0] = 0;
				if (i == 0)
				{
					free(*line);
					*line = ft_strjoin(NULL, buf);
				}
				else
					*line = ft_strjoin(*line, buf);
				nl_chr_pos[0] = '\n';
				shift_buf_to_nl(buf);
				if (buf + BUFFER_SIZE != find_str_start_end(buf, 1))
					read_ret = read(fd, find_str_start_end(buf, 1),
						buf + BUFFER_SIZE - find_str_start_end(buf, 1));
				break;
			}
		}
		if (read_ret == 0 && res == 0 && i == 0)
		{
				*line = malloc(1);
				**line = '\0';
		}
	}
	else
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1 || line == NULL)
			return (-1);
		buf[read_ret] = 0;
		*line = NULL;
		return (get_next_line(fd, line));
	}
	if (read_ret == 0 && buf[0] != 0)
		res = 1;
	if (read_ret > 1)
		res = 1;
	return (res);
}

#include <fcntl.h>
int main()
{
//	char* line;
//	int fd;
//	int gnl_ret = 0;
//
//	fd = open("/Users/tphlogis/Documents/My_projects/gnl/42TESTERS-GNL-master/files/alphabet", O_RDWR);
//	while ((gnl_ret = get_next_line(fd, &line)) == 1)
//	{
//		printf("%s %d\n", line, gnl_ret);
//	}
//	printf("%s %d\n", line, gnl_ret);
//	close(fd);
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("/Users/tphlogis/Documents/My_projects/gnl/42TESTERS-GNL-master/files/alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
//	while (--j > 0)
//		free(lineadress[j - 1]);
	j = 1;

	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_lines", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 9)
		printf("\nRight number of lines\n");
	else if (j != 9)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
}
