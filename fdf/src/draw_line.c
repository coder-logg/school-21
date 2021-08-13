#include <printf.h>
#include "fdf.h"

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

void	shift_one(t_point *point, int shift_x, int shift_y, double scale)
{
	point->x += shift_x * scale;
	point->y += shift_y * scale;
}

void	zoom_one(t_point *point, double scale, double prev_scale)
{
	point->x /= prev_scale;
	point->x *= scale;

	point->y /= prev_scale;
	point->y *= scale;
}

void	draw_line_brezenhem(t_point p1, t_point p2, t_fdf fdf, int color)
{
//	zoom_one(&p1, fdf.map->zoom, fdf.map->prev_scale);
//	zoom_one(&p2, fdf.map->zoom, fdf.map->prev_scale);
	rotate_x(&p1, fdf.map->angle_x); rotate_y(&p1, fdf.map->angle_y);
	rotate_z(&p1, fdf.map->angle_z);

	rotate_x(&p2, fdf.map->angle_x); rotate_y(&p2, fdf.map->angle_y);
	rotate_z(&p2, fdf.map->angle_z);

	do_isometric(&p1, fdf.map->angle_iso);
	do_isometric(&p2, fdf.map->angle_iso);

	p1.x += fdf.win->size_x / 2 - fdf.map->central_point->x;
	p1.y += fdf.win->size_y / 2 - fdf.map->central_point->y;

	p2.x += fdf.win->size_x / 2 - fdf.map->central_point->x;
	p2.y += fdf.win->size_y / 2 - fdf.map->central_point->y;
	
	shift_one(&p1, fdf.map->shift.x, fdf.map->shift.y, fdf.map->zoom);
	shift_one(&p2, fdf.map->shift.x, fdf.map->shift.y, fdf.map->zoom);



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
//	mlx_pixel_put(fdf.win->mlx_ptr, fdf.win->win_ptr, p2.x, p2.y, color);
	put_pixel(fdf, p2.x, p2.y, color);
	while(p1.x != p2.x || p1.y != p2.y)
	{
		put_pixel(fdf, p1.x, p1.y, color);
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