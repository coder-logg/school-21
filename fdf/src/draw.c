#include "fdf.h"

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

void shift(t_map *map, int shift_x, int	shift_y)
{
	map->shift.x += shift_x;
	map->shift.y += shift_y;
	for_each_points_in_map(*map, shift_x * map->zoom, sum, 1);
	for_each_points_in_map(*map, shift_y * map->zoom, sum, 2);
}

void zoom(t_map *map, int scale)
{
	map->zoom = scale;
	for_each_points_in_map(*map, scale, multiple, 3);
//	for_each_points_in_map(*map, scale /, multiple, 4);
}

int	rgb(unsigned char r, unsigned char g, unsigned char b)
{
	int color;

	color = r;
	color <<= 8;
	color |= g;
	color <<= 8;
	color |= b;
	return (color);
}

void do_isometric(t_point *point, double angle)
{
	int previous_x;

	previous_x = point->x;
	point->x = (point->x - point->y) * cos(angle);
	point->y = (previous_x + point->y) * sin(angle) - point->z;
}

// arr = [color, angle]
void	draw_line(t_point p1, t_point p2, t_window win, int color)
{
	int deltax = abs(p2.x - p1.x);
	int deltay = abs(p2.y - p1.y);
	int sign_x;
	if (p1.x < p2.x)
		sign_x = 1;
	else
		sign_x = -1;
	int sign_y;
	if (p1.y < p2.y)
		sign_y = 1;
	else
		sign_y = -1;
	int error = deltax - deltay;
	mlx_pixel_put(win.mlx_ptr, win.win_ptr, p2.x, p2.y, color);
	while(p1.x != p2.x || p1.y != p2.y)
	{
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, p1.x, p1.y, color);
		int err2 = error * 2;
		if (err2 > -deltay)
		{
			error -= deltay;
			p1.x += sign_x;
		}
		if (err2 < deltax)
		{
			error += deltax;
			p1.y += sign_y;
		}
	}
}

void	rotate(t_map *map, double angle)
{
	map->angle = angle;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			do_isometric(&map->matrix[i][j], angle);
			j++;
		}
		i++;
	}

}

void show_map(t_map *map, t_window *window)
{
	unsigned int	i;
	unsigned int	j;
	int				color;

	i = 0;
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			color = rgb(0, 255, 0);
			if (j != (*map).width - 1)
			{
				if ((*map).matrix[i][j].z  || (*map).matrix[i][j + 1].z)
					color = rgb(240,248,255);
				draw_line((*map).matrix[i][j], (*map).matrix[i][j + 1], (*window), color);
			}
			color = rgb(0, 255, 0);
			if (i != (*map).height - 1)
			{
				if ((*map).matrix[i][j].z  || (*map).matrix[i + 1][j].z)
					color = rgb(240,248,255);
				draw_line((*map).matrix[i][j], (*map).matrix[i + 1][j], (*window), color);
			}
			j++;
		}
		i++;
	}
}

void	draw(t_map map, t_window window)
{
	zoom(&map, 50);
	for_each_points_in_map(map, 3, multiple, 4);
	rotate(&map, 0.21);
	shift(&map, 12, 5);
	print_points(map.matrix, map.height, map.width);
	show_map(&map, &window);
}