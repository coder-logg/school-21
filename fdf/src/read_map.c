#include "fdf.h"

void	parse_line_for_points(char *line, t_map *map)
{
	char				**splited_line;
	static unsigned int	y;
	unsigned int		x;

	splited_line = ft_split(line, ' ');
	x = 0;
	*(map->matrix + y) = ft_calloc(map->m_width, sizeof(t_point));
	while(x < map->m_width)
	{
		init_point(*(map->matrix + y) + x, x, y, ft_atoi(splited_line[x]));
		x++;
	}
	y++;
	free_split(splited_line, map->m_width);
}

void	parse_map(int fd, t_map *map)
{
	char			*line;
	unsigned int	i;
	int				gnlres;

	i = 1;
	gnlres = get_next_line(fd, &line);
	while (gnlres > 0)
	{
		parse_line_for_points(line, map);
		free(line);
		gnlres = get_next_line(fd, &line);
	}
	parse_line_for_points(line, map);
	free(line);
}

t_map	read_map(const char *file_name)
{
	int				fd;
	t_map 			map;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File open error\n");
	map.matrix = ft_calloc(set_map_size(fd, &map)->m_height, sizeof(t_point *));
	close(fd);
	fd = open(file_name, O_RDONLY);
	parse_map(fd, &map);
	return map;
}