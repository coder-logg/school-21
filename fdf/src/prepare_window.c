#include "fdf.h"

void	*get_window()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "fdf");
	return (win_ptr);
}

void prepare_window(t_window *window)
{
	window->mlx_ptr = mlx_init();
	window->size_x = 1500;
	window->size_y = 1000;
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->size_x, window->size_y, "fdf");
	mlx_key_hook(window->win_ptr, key_event_listener, window);
	mlx_hook(window->win_ptr, 17, 1L<<17, ft_close, NULL);
}