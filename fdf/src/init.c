#include "fdf.h"

void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(*map));
	map->zoom = 20;
	map->angle_iso = 0.523599;
	map->z_offset = 2;
}

void	init_point(t_point *point_to_ini, int x, int y, int z)
{
	point_to_ini->x = x;
	point_to_ini->y = y;
	point_to_ini->z = z;
}

void	init_fdf(t_fdf *fdf, char *file_name)
{
	fdf->win->mlx_ptr = mlx_init();
	fdf->win->size_x = WINDOW_WIDTH;
	fdf->win->size_y = WINDOW_HEIGHT;
	file_name = ft_strjoin("fdf [", file_name);
	if (file_name == NULL)
		ft_error("malloc error\n");
	fdf->win->win_ptr = mlx_new_window(fdf->win->mlx_ptr, fdf->win->size_x,
			fdf->win->size_y, file_name);
	free(file_name);
	fdf->map->central_point
		= &fdf->map->matrix[fdf->map->height / 2][fdf->map->width / 2];
	fdf->img->bits_per_pixel = 32;
	fdf->img->size_line = fdf->map->width * 8;
	fdf->img->endian = 0;
	fdf->img->img_ptr = mlx_new_image(fdf->win->mlx_ptr, fdf->win->size_x,
			fdf->win->size_y);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr,
			&fdf->img->bits_per_pixel,
			&fdf->img->size_line, &fdf->img->endian);
}
