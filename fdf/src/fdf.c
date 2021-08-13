#include <printf.h>
#include "fdf.h"

void	add_listeners(t_fdf *fdf)
{
	mlx_key_hook(fdf->win->win_ptr, key_event_listener, fdf);
	mlx_hook(fdf->win->win_ptr, 17, 1L << 17, ft_close, fdf->map);
}

void prepare(t_fdf *fdf)
{
	fdf->win->mlx_ptr = mlx_init();
	fdf->win->size_x = WINDOW_WIDTH;
	fdf->win->size_y = WINDOW_HEIGHT;
	fdf->win->win_ptr = mlx_new_window(fdf->win->mlx_ptr, fdf->win->size_x,
									   fdf->win->size_y, "fdf");
	fdf->map->central_point =
			&fdf->map->matrix[fdf->map->height / 2][fdf->map->width / 2];
//	fdf->img->bits_per_pixel = 32;
	fdf->img->size_line = fdf->map->width * 8; // maybe error
	fdf->img->endian = 0;
	fdf->img->img_ptr = mlx_new_image(fdf->win->mlx_ptr, fdf->win->size_x,
									  fdf->win->size_y);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bits_per_pixel,
									   &fdf->img->size_line, &fdf->img->endian);
}

int main(int argc, char **argv)
{
	t_fdf		fdf;
	t_map		map;
	t_window	window;
	t_img		img;

	if (argc != 2)
		ft_error("usage: ./fdf [path to file with map]\n");
	map = read_map(argv[1]);
	fdf.map = &map;
	fdf.win = &window;
	fdf.img = &img;
	print_points(fdf.map->matrix, fdf.map->height, fdf.map->width);
	prepare(&fdf);
	add_listeners(&fdf);
	draw(fdf);
	mlx_loop(window.mlx_ptr);
////	while(1);
	return (0);
}