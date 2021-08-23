#include "fdf_bonus.h"

void	parse_line_for_points(char *line, t_map *map)
{
	char		**splited_line;
	static int	y;
	int			x;

	splited_line = ft_split(line, ' ');
	if (splited_line == NULL)
		ft_error("malloc error\n");
	x = 0;
	*(map->matrix + y) = ft_calloc(map->width, sizeof(t_point));
	if (*(map->matrix + y) == NULL)
		ft_error("malloc error\n");
	while (x < (int)(map->width))
	{
		init_point(*(map->matrix + y) + x, x, y, ft_atoi(splited_line[x]));
		x++;
	}
	y++;
	free_split(splited_line, map->width);
}

void	parse_map(int fd, t_map *map)
{
	char			*line;
	int				gnlres;

	gnlres = get_next_line(fd, &line);
	while (gnlres > 0)
	{
		parse_line_for_points(line, map);
		free(line);
		gnlres = get_next_line(fd, &line);
	}
	free(line);
}

void	read_map(const char *file_name, t_map *map)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File open error\n");
	init_map(map);
	map->matrix = ft_calloc(set_map_size(fd, map)->height, sizeof(t_point *));
	if (map->matrix == NULL)
		ft_error("malloc error\n");
	close(fd);
	fd = open(file_name, O_RDONLY);
	parse_map(fd, map);
	close(fd);
}
