#include "fdf_bonus.h"

static void	put_pixel(t_fdf fdf, int x, int y, int color)
{
	int	i;

	if (x > 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		i = (x * fdf.img->bits_per_pixel / 8) + (y * fdf.img->size_line);
		fdf.img->addr[i] = color;
		fdf.img->addr[++i] = color >> 8;
		fdf.img->addr[++i] = color >> 16;
	}
}

static void	zoom_one(t_point *point, int scale)
{
	point->x *= scale;
	point->y *= scale;
	if (point->z != 0)
	{
		if (scale > 0)
			point->z += round(scale * 0.5);
		else
			point->z -= round(scale * 0.5);
	}
}

static void	apply_coeffs_to_point(t_point *point, t_fdf fdf)
{
	if (point->z != 0)
		point->z *= fdf.map->zoom / fdf.map->z_offset;
	zoom_one(point, fdf.map->zoom);
	point->x -= (fdf.map->width * fdf.map->zoom) / 2;
	point->y -= (fdf.map->height * fdf.map->zoom) / 2;
	rotate_x(point, fdf.map->angle_x);
	rotate_y(point, fdf.map->angle_y);
	rotate_z(point, fdf.map->angle_z);
	if (!(fdf.map->projection))
		do_isometric(point, fdf.map->angle_iso);
	point->x += fdf.map->shift.x * fdf.map->zoom;
	point->y += fdf.map->shift.y * fdf.map->zoom;
	point->x += (WINDOW_WIDTH / 2) - fdf.map->central_point->x;
	point->y += (WINDOW_HEIGHT / 2) - fdf.map->central_point->y;
}

static int	ini_sign_delta(t_point p1, t_point p2, t_point *sig, t_point *delt)
{
	delt->x = abs(p2.x - p1.x);
	delt->y = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		sig->x = 1;
	else
		sig->x = -1;
	if (p1.y < p2.y)
		sig->y = 1;
	else
		sig->y = -1;
	return (delt->x - delt->y);
}

void	draw_line_brezenhem(t_point p1, t_point p2, t_fdf fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		err[2];

	apply_coeffs_to_point(&p1, fdf);
	apply_coeffs_to_point(&p2, fdf);
	err[0] = ini_sign_delta(p1, p2, &sign, &delta);
	put_pixel(fdf, p2.x, p2.y, get_color(p2, p1, p2, delta));
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, p1, p2, delta));
		err[1] = err[0] * 2;
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += sign.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
