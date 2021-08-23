#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

void	set_color(t_map *map, int max_z, int min_z)
{
	double			per;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			per = percent(max_z, min_z, map->matrix[i][j].z);
			if (per < 0.2)
				map->matrix[i][j++].color = (COLOR_WHITE);
			else if (per < 0.4)
				map->matrix[i][j++].color = (COLOR_UP);
			else if (per < 0.6)
				map->matrix[i][j++].color = (COLOR_ZERO);
			else if (per < 0.8)
				map->matrix[i][j++].color = (COLOR_DEEP);
			else
				map->matrix[i][j++].color = (COLOR_RED);
		}
		i++;
	}
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		perc = percent(start.x, end.x, current.x);
	else
		perc = percent(start.y, end.y, current.y);
	r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, perc);
	g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	b = get_light(start.color & 0xFF, end.color & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}
