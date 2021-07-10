#include "fdf.h"
#include <stdio.h>
int key_event_listener(int key, t_window *window)
{
	if (key == 53)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(0);
	}
	return (0);
}

int ft_close(void *param)
{
	(void)param;
	exit(0);
}