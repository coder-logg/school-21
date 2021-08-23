#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1500

# define BACKGROUND 0x202020
# define TEXT_COLOR 0x00ff00
# define COLOR_UP			0xEF8633
# define COLOR_RED			0xCC3333
# define COLOR_ZERO			0x33FF00
# define COLOR_WHITE		0xFFFFCC
# define COLOR_DEEP			0x00CCFF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_point;

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	int				zoom;
	double			angle_iso;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	t_point			shift;
	double			z_offset;
	char			projection;
	t_point			*central_point;
	t_point			**matrix;
}				t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	char	*addr;
}			t_img;

typedef struct s_window
{
	unsigned int	size_x;
	unsigned int	size_y;
	void			*win_ptr;
	void			*mlx_ptr;
}				t_window;

typedef struct s_fdf
{
	t_window	*win;
	t_img		*img;
	t_map		*map;
}			t_fdf;

t_map	*set_map_size(int fd, t_map *map);
void	init_point(t_point *point_to_ini, int x, int y, int z);
void	init_fdf(t_fdf *fdf, char *file_name);
void	init_map(t_map *map);
void	free_split(char **splited_line, unsigned int elm_in_line);
void	read_map(const char *file_name, t_map *map);
int		key_event_listener(int key, t_fdf *fdf);
void	do_isometric(t_point *point, double angle);
void	rotate_x(t_point *point, double angle);
void	rotate_y(t_point *point, double angle);
void	rotate_z(t_point *point, double angle);
int		ft_close(t_map *map);
void	draw(t_fdf fdf);
void	clean_matrix(t_point **matrix, unsigned int height);
void	draw_line_brezenhem(t_point p1, t_point p2, t_fdf fdf);
void	print_menu(t_fdf *fdf);
int		get_max_min_z(t_point **arr, int h, int w, long (*comp_f)(long, long));
void	set_color(t_map *map, int max_z, int min_z);
int		get_color(t_point current, t_point start, t_point end, t_point delta);

#endif
