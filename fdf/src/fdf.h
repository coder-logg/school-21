#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>


# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1500
# define BACKGROUND 0x202020


typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}			t_point;

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	double			zoom;
	double			angle_iso;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	t_point 		shift;
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

//typedef union  u_color
//{
//	char b:8;
//	char g:8;
//	char r:8;
//}				u_color;

t_map	*set_map_size(int fd, t_map *map);
void	init_point(t_point *point_to_ini, int x, int y, int z);
int		rgb(unsigned char r, unsigned char g, unsigned char b);
void	print_points(t_point **points, unsigned nbr_lines, unsigned nbr_columns); // to delete
void	free_split(char **splited_line, unsigned int elm_in_line);
t_map	read_map(const char *file_name);
//void 	prepare(t_window *win);
int 	key_event_listener(int key, t_fdf *fdf);
void	rotate(t_map *map, double angle, void (*ft_rot)(t_point *, double));
void	do_isometric(t_point *point, double angle);
void	rotate_x(t_point *point, double angle);
void	shift(t_map *map, int shift_x, int	shift_y);
void	show_map(t_map *map, t_window *window, t_fdf fdf);
void	rotate_y(t_point *point, double angle);
void	rotate_z(t_point *point, double angle);
void	zoom(t_map *map, double scale);
int		ft_close(t_map *map);
void	draw(t_fdf fdf);
void	clean_matrix(t_point **matrix, unsigned int height);
void	for_each_points_in_map(t_map map, int nbr, long (*math_oper)(long, long),
							char change_mask);
void	draw_line_brezenhem(t_point p1, t_point p2, t_fdf fdf, int color);
void	put_img(t_fdf fdf);
void	put_pixel(t_fdf fdf, int x, int y, int color);
void	background(t_fdf fdf);
long	sum(long n1, long n2);
long	minus(long n1, long n2);
long	devide(long n1, long n2);
long	multiple(long n1, long n2);

#endif
