#include "fdf_bonus.h"

static void	background(t_fdf fdf)
{
	int	i;
	int	*img;
	int	tmp;

	tmp = WINDOW_WIDTH * WINDOW_HEIGHT;
	ft_memset(fdf.img->addr, 0, tmp * (fdf.img->bits_per_pixel / 8));
	img = (int *)(fdf.img->addr);
	i = 0;
	while (i < tmp)
		img[i++] = BACKGROUND;
}

static void	show_map(t_map *map, t_fdf fdf)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j != map->width - 1)
				draw_line_brezenhem(map->matrix[i][j],
					map->matrix[i][j + 1], fdf);
			if (i != map->height - 1)
				draw_line_brezenhem(map->matrix[i][j],
					map->matrix[i + 1][j], fdf);
			j++;
		}
		i++;
	}
}

void	draw(t_fdf fdf)
{
	background(fdf);
	show_map(fdf.map, fdf);
	mlx_put_image_to_window(fdf.win->mlx_ptr, fdf.win->win_ptr,
		fdf.img->img_ptr, 0, 0);
}
