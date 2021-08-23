#include "fdf.h"

void	do_isometric(t_point *point, double angle)
{
	int	previous_x;

	previous_x = point->x;
	point->x = (point->x - point->y) * cos(angle);
	point->y = (previous_x + point->y) * sin(angle) - point->z;
}
