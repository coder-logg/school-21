#include "fdf.h"

#include "stdio.h"
void	print_points(t_point **points, unsigned nbr_lines, unsigned nbr_columns)
{
	unsigned i = 0;
	while (i < nbr_lines)
	{
		unsigned j = 0;
		while (j < nbr_columns)
		{
			if (points[i][j].z != 0)
				printf("\x1b[95m");
			printf("(%d, %d, %d) ",points[i][j].x, points[i][j].y, points[i][j].z);
			printf("\x1b[0m");
			j++;
		}
		i++;
		printf("\n");
	}
}

void for_each_points_in_map(t_map map, int nbr, long (*math_oper)(long, long),
							char change_mask)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (change_mask & 1)
				map.matrix[i][j].x = math_oper(map.matrix[i][j].x, nbr);
			if (change_mask & 2)
				map.matrix[i][j].y = math_oper(map.matrix[i][j].y, nbr);
			if (change_mask & 4)
				map.matrix[i][j].z = math_oper(map.matrix[i][j].z, nbr);
			j++;
		}
		i++;
	}
}

void clean_matrix(t_point **matrix, unsigned int height)
{
	while (height > 0)
	{
		free(matrix[height - 1]);
		height--;
	}
}

void free_split(char **splited_line, unsigned int elm_in_line)
{
	while (elm_in_line > 0)
	{
		free(splited_line[elm_in_line - 1]);
		elm_in_line--;
	}
	free(splited_line);
}

void	init_point(t_point *point_to_ini, int x, int y, int z)
{
	point_to_ini->x = x;
	point_to_ini->y = y;
	point_to_ini->z = z;
}

t_map	*set_map_size(int fd, t_map *map)
{
	int				gnlres;
	char			*line;
	char			**splited_line;

	map->width = 0;
	map->height = 1;
	gnlres = get_next_line(fd, &line);
	splited_line = ft_split(line, ' ');
	while (splited_line[map->width])
		map->width++;
	free_split(splited_line, map->width);
	while (gnlres > 0)
	{
		free(line);
		gnlres = get_next_line(fd, &line);
		map->height++;
	}
	free(line);
	return (map);
}