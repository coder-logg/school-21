#include "fdf.h"

void zoom(t_map map, int scale)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map.m_height)
	{
		j = 0;
		while (j < map.m_width)
		{
			if (scale < 0)
			{
				map.matrix[i][j].x /= scale;
				map.matrix[i][j].y /= scale;
				map.matrix[i][j++].z /= scale;
				continue;
			}
				map.matrix[i][j].x *= scale;
				map.matrix[i][j].y *= scale;
				map.matrix[i][j++].z *= scale;
		}
		i++;
	}
}

int	get_color(unsigned char r, unsigned char g, unsigned char b)
{
	int color;

	color = r;
	color <<= 8;
	color |= g;
	color <<= 8;
	color |= b;
	return (color);
}

void draw_simple_line(t_point p1, t_point p2, t_window win, int color)
{

}

void	draw_line(t_point p1, t_point p2, t_window win, int color)
{
	int y;
	int x;
	int dir_y;
	int err;

//	if (p1.x == p2.x || p1.y == p2.y)

	err = 0;
	y = p1.y;
	x = p1.x;
	dir_y = p2.y - p1.y;
	if (dir_y > 0)
		dir_y = 1;
	else if (dir_y < 0)
		dir_y = -1;
	while (x < p2.x)
	{
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, color);
		err += p2.y - p1.y + 1;
		if (err >= p2.y - p1.y + 1)
		{
			y = y + dir_y;
			err =err - (p2.x - p1.x + 1);
		}
		x++;
	}
}

void	draw(t_map map, t_window window)
{
	unsigned int	i;
	unsigned int	j;

	zoom(map, 20);
	i = 0;
	while (i < map.m_height - 1)
	{
		j = 0;
		while (j < map.m_width - 1)
		{
			draw_line(map.matrix[i][j], map.matrix[i][j + 1], window, get_color(255, 0, 0));
			draw_line(map.matrix[i][j], map.matrix[i + 1][j], window, get_color(0, 255, 0));
			j++;
		}
		i++;
	}
}