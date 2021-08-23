#include "fdf.h"

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
	if (key == 43)
		fdf->map->z_offset *= 0.97;
	if (key == 47)
		fdf->map->z_offset /= 0.97;
	if (key == 69)
		(fdf->map->zoom)++;
	if (key == 78)
		(fdf->map->zoom)--;
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
	if (key == 126 || key == 125 || key == 123 || key == 124
		|| key == 69 || key == 78 || key == 43 || key == 47)
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
