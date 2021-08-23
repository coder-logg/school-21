#include "fdf.h"

void	add_listeners(t_fdf *fdf)
{
	mlx_hook(fdf->win->win_ptr, 2, 0, key_event_listener, fdf);
	mlx_hook(fdf->win->win_ptr, 17, 1L << 17, ft_close, fdf->map);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	t_window	window;
	t_map		map;
	t_img		img;

	if (argc != 2)
		ft_error("usage: ./fdf [path to file with map]\n");
	read_map(argv[1], &map);
	set_color(&map, get_max_min_z(map.matrix, map.height, map.width, max),
		get_max_min_z(map.matrix, map.height, map.width, min));
	fdf.map = &map;
	fdf.win = &window;
	fdf.img = &img;
	init_fdf(&fdf, argv[1]);
	add_listeners(&fdf);
	draw(fdf);
	mlx_loop(window.mlx_ptr);
	return (0);
}
