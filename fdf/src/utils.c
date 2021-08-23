#include "fdf.h"

int	get_max_min_z(t_point **arr, int h, int w, long (*compare_f)(long, long))
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = arr[0][0].z;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (compare_f(arr[i][j].z, ret) != ret)
				ret = arr[i][j].z;
			j++;
		}
		i++;
	}
	return (ret);
}

void	clean_matrix(t_point **matrix, unsigned int height)
{
	while (height > 0)
	{
		free(matrix[height - 1]);
		height--;
	}
}

void	free_split(char **splited_line, unsigned int elm_in_line)
{
	while (elm_in_line > 0)
	{
		free(splited_line[elm_in_line - 1]);
		elm_in_line--;
	}
	free(splited_line);
}

t_map	*set_map_size(int fd, t_map *map)
{
	int		gnlres;
	char	*line;
	char	**splited_line;

	map->width = 0;
	map->height = 0;
	gnlres = get_next_line(fd, &line);
	splited_line = ft_split(line, ' ');
	if (splited_line == NULL)
		ft_error("malloc error\n");
	while (splited_line[map->width])
		map->width++;
	free_split(splited_line, map->width);
	while (gnlres > 0)
	{
		free(line);
		map->height++;
		gnlres = get_next_line(fd, &line);
	}
	free(line);
	return (map);
}
