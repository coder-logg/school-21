#include "fdf.h"

void	background(t_fdf fdf)
{
	int		i;
	int		*img;
	int		tmp;

	tmp = WINDOW_WIDTH * WINDOW_HEIGHT;
	ft_memset(fdf.img->addr, 0, tmp * (fdf.img->bits_per_pixel / 8));
	img = (int *)(fdf.img->addr);
	i = 0;
	while (i < tmp)
			img[i++] = BACKGROUND;
}

void	put_pixel(t_fdf fdf, int x, int y, int color)
{
	int	i;

	if (x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		i = (x * fdf.img->bits_per_pixel / 8) + (y * fdf.img->size_line);
		fdf.img->addr[i] = color;
		fdf.img->addr[++i] = color >> 8;
		fdf.img->addr[++i] = color >> 16;
	}
}


void	put_img(t_fdf fdf)
{
	background(fdf);
}