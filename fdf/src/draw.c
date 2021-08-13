#include <printf.h>
#include "fdf.h"

void zoom(t_map *map, double scale)
{
	int	prev_scale;
	unsigned int	i;
	unsigned int	j;

	prev_scale = map->zoom;
	map->zoom += scale;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x /= prev_scale;
			map->matrix[i][j].x *= map->zoom;

			map->matrix[i][j].y /= prev_scale;
			map->matrix[i][j].y *= map->zoom;

			if (map->matrix[i][j].z != 0)
			{
				if (scale > 0)
					map->matrix[i][j].z += map->zoom * 0.05;
				else
					map->matrix[i][j].z -= map->zoom * 0.05;
			}
			j++;
		}
		i++;
	}
}

void show_map(t_map *map, t_window *window, t_fdf fdf)
{
	unsigned int	i;
	unsigned int	j;
	int				color;

	i = 0;
	print_points(fdf.map->matrix, fdf.map->height, fdf.map->width);
	printf("\n");
//	for_each_points_in_map(*map, window->size_x / 2 - map->central_point->x,
//						   sum, 1);
//	for_each_points_in_map(*map, window->size_y / 2 - map->central_point->y,
//						   sum, 2);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			color = rgb(0, 255, 0);
			if (j != map->width - 1)
			{
				if (map->matrix[i][j].z  || map->matrix[i][j + 1].z)
					color = rgb(255,255,0);
				draw_line_brezenhem((*map).matrix[i][j],
									map->matrix[i][j + 1], fdf, color);
			}
			color = rgb(0, 255, 0);
			if (i != map->height - 1)
			{
				if (map->matrix[i][j].z  || map->matrix[i + 1][j].z)
					color = rgb(255,255,0);
				draw_line_brezenhem((*map).matrix[i][j],
									map->matrix[i + 1][j], fdf, color);
			}
			j++;
		}
		i++;
	}
}

void draw(t_fdf fdf)
{
	zoom(fdf.map, 10);
	put_img(fdf);
	show_map(fdf.map, fdf.win, fdf);
	mlx_put_image_to_window(fdf.win->mlx_ptr, fdf.win->win_ptr, fdf.img->img_ptr, 0, 0);
}