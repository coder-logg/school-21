#include "fdf.h"
#include <stdio.h>

int key_event_listener(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->win->mlx_ptr, fdf->win->win_ptr);
		ft_close(fdf->map);
	}
	if (key == 126)
		fdf->map->shift.y -= 3;
	if (key == 125)
		fdf->map->shift.y += 3;
	if (key == 123)
		fdf->map->shift.x -= 3;
	if (key == 124)
		fdf->map->shift.x += 3;

	if (key == 13)
		fdf->map->angle_x -= 0.2;
	if (key == 1)
		fdf->map->angle_x += 0.2;

	if (key == 0)
		fdf->map->angle_y += 0.2;
	if (key == 12)
		fdf->map->angle_y -= 0.2;

	if (key == 2)
		fdf->map->angle_z += 0.2;
	if (key == 14)
		fdf->map->angle_z -= 0.2;
	// zoom
	if (key == 69)
		zoom(fdf->map, 1);
	if (key == 78)
		zoom(fdf->map, -1);

	if (key == 126 || key == 125 || key == 123 || key == 124 || key == 13
	|| key == 1 || key == 0 || key == 12 || key == 14 || key == 2 || key == 69 || key ==78)
	{
		mlx_clear_window(fdf->win->mlx_ptr, fdf->win->win_ptr);
		ft_bzero(fdf->img->addr, WINDOW_WIDTH * WINDOW_HEIGHT);
		background(*fdf);
		show_map(fdf->map, fdf->win, *fdf);
		printf("%.2f\n", fdf->map->zoom);
		mlx_put_image_to_window(fdf->win->mlx_ptr, fdf->win->win_ptr, fdf->img->img_ptr, 0, 0);
	}
	return (0);
}

int ft_close(t_map *map)
{
	clean_matrix(map->matrix, map->height);
	exit(0);
}