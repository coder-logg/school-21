#include <printf.h>
#include "fdf.h"

void do_isometric(t_point *point, double angle)
{
	int	previous_x;

	previous_x = point->x;
	point->x = (point->x - point->y) * cos(angle);
	point->y = (previous_x + point->y) * sin(angle) - point->z;
}

void	rotate_x(t_point *point, double angle)
{
	int			tmp;

	tmp = point->y;
	point->y = tmp * cos(angle) + point->z * sin(angle);
	point->z = -tmp * sin(angle) + point->z * cos(angle);
}

void	rotate_y(t_point *point, double angle)
{
	int			tmp;

	tmp = point->x;
	point->x = tmp * cos(angle) + point->z * sin(angle);
	point->z = -tmp * sin(angle) + point->z * cos(angle);
}

void	rotate_z(t_point *point, double angle)
{
	int			tmp;

	tmp = point->x;
	point->x = tmp * cos(angle) - point->y * sin(angle);
	point->y = -tmp * sin(angle) + point->y * cos(angle);
}

void	rotate(t_map *map, double angle, void (*ft_rot)(t_point *, double))
{
	map->angle_iso = angle;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_rot(&map->matrix[i][j], angle);
			j++;
		}
		i++;
	}
}


