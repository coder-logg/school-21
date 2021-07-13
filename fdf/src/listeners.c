#include "fdf.h"
#include <stdio.h>

int key_event_listener(int key, t_map *map)
{
	if (key == 53)
	{
//		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		ft_close(map);
	}
	return (0);
}

int ft_close(t_map *map)
{
	clean_matrix(map->matrix, map->height);
	exit(0);
}