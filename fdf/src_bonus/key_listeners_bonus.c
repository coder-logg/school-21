#include "fdf_bonus.h"

static void	update_coeffs(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->map->shift.y -= 3;
	if (key == 125)
		fdf->map->shift.y += 3;
	if (key == 123)
		fdf->map->shift.x -= 3;
	if (key == 124)
		fdf->map->shift.x += 3;
	if (key == 88)
		fdf->map->angle_y += 0.2;
	if (key == 86)
		fdf->map->angle_y -= 0.2;
	if (key == 43)
		fdf->map->z_offset *= 0.97;
	if (key == 47)
		fdf->map->z_offset /= 0.97;
	if (key == 91)
		fdf->map->angle_x += 0.2;
	if (key == 84)
		fdf->map->angle_x -= 0.2;
	if (key == 69)
		(fdf->map->zoom)++;
	if (key == 78)
		(fdf->map->zoom)--;
}

static void	update_cfs(int key, t_fdf *fdf)
{
	if (key == 89)
		fdf->map->angle_z += 0.2;
	if (key == 83)
		fdf->map->angle_z -= 0.2;
	if (key == 35)
	{
		fdf->map->angle_x = 0;
		fdf->map->angle_y = 0;
		fdf->map->angle_z = 0;
		fdf->map->angle_iso = 0;
		fdf->map->projection = 1;
	}
	if (key == 34)
	{
		fdf->map->zoom = 10;
		fdf->map->angle_iso = 0.523599;
		fdf->map->z_offset = 2;
		fdf->map->projection = 0;
	}
}

int	key_event_listener(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->win->mlx_ptr, fdf->win->win_ptr);
		ft_close(fdf->map);
	}
	if (key == 46)
	{
		mlx_clear_window(fdf->win->mlx_ptr, fdf->win->win_ptr);
		print_menu(fdf);
	}
	update_coeffs(key, fdf);
	update_cfs(key, fdf);
	if (key == 126 || key == 125 || key == 123 || key == 124 || key == 84
		|| key == 91 || key == 88 || key == 86 || key == 83 || key == 89
		|| key == 69 || key == 78 || key == 43 || key == 47 || key == 35
		|| key == 34)
	{
		mlx_clear_window(fdf->win->mlx_ptr, fdf->win->win_ptr);
		draw(*fdf);
	}
	return (0);
}

int	ft_close(t_map *map)
{
	clean_matrix(map->matrix, map->height);
	exit(0);
}
