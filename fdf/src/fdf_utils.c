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

void free_split(char **splited_line, unsigned int elm_in_line)
{
	while (elm_in_line > 0)
	{
		free(splited_line[elm_in_line - 1]);
		elm_in_line--;
	}
	free(splited_line);
}

void	init_point(t_point *point_to_ini, unsigned int x, unsigned int y, int z)
{
	point_to_ini->x = x;
	point_to_ini->y = y;
	point_to_ini->z = z;
}

t_point	*create_point(unsigned int x, unsigned int y, int z)
{
	t_point	*new_point;

	new_point = malloc(sizeof(t_point));
	init_point(new_point, x, y, z);
	return (new_point);
}

t_map	*set_map_size(int fd, t_map *map)
{
	int				gnlres;
	char			*line;
	char			**splited_line;

	map->m_width = 0;
	map->m_height = 1;
	gnlres = get_next_line(fd, &line);
	splited_line = ft_split(line, ' ');
	while (splited_line[map->m_width])
		map->m_width++;
	free_split(splited_line, map->m_width);
	while (gnlres > 0)
	{
		free(line);
		gnlres = get_next_line(fd, &line);
		map->m_height++;
	}
	free(line);
	return (map);
}