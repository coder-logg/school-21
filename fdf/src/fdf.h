#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

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
	unsigned int	zoom;
	double			angle;
	t_point 		shift;
	t_point			**matrix;
}				t_map;

typedef struct s_window
{
	unsigned int	size_x;
	unsigned int	size_y;
	void			*win_ptr;
	void			*mlx_ptr;
}				t_window;

t_map	*set_map_size(int fd, t_map *map);
void	init_point(t_point *point_to_ini, unsigned int x, unsigned int y, int z);
t_point	*create_point(unsigned int x, unsigned int y, int z);
void	print_points(t_point **points, unsigned nbr_lines, unsigned nbr_columns); // to delete
void	free_split(char **splited_line, unsigned int elm_in_line);
t_map	read_map(const char *file_name);
void 	prepare_window(t_window *window);
int 	key_event_listener(int key, t_map *map);
int		ft_close(t_map *map);
void	draw(t_map map, t_window window);
void	clean_matrix(t_point **matrix, unsigned int height);
long	sum(long n1, long n2);
long	minus(long n1, long n2);
long	devide(long n1, long n2);
long	multiple(long n1, long n2);

#endif
