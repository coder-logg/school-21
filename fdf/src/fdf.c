#include "fdf.h"

int main(int argc, char **argv)
{
	t_map map;
	t_window window;

	if (argc != 2)
		ft_error("usage: ./fdf [path to file with map]\n");
	map = read_map(argv[1]);
	prepare_window(&window);
	mlx_loop(window.win_ptr);
//	while(1);
//	print_points(map.matrix, map.m_height, map.m_width);
	return (0);
}