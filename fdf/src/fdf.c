#include "fdf.h"

int main(int argc, char **argv)
{
	t_map		map;
	t_window	window;

	if (argc != 2)
		ft_error("usage: ./fdf [path to file with map]\n");
	map = read_map(argv[1]);
	prepare_window(&window);
	mlx_key_hook(window.win_ptr, key_event_listener, &map);
	mlx_hook(window.win_ptr, 17, 1L<<17, ft_close, &map);
	draw(map, window);
	mlx_loop(window.mlx_ptr);
//	while(1);
//	print_points(map.matrix, map.height, map.width);
	return (0);
}