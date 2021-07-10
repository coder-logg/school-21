#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
	int				z;
}			t_point;

typedef struct s_map
{
	unsigned int	m_width;
	unsigned int	m_height;
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
void	*get_window();
void 	prepare_window(t_window *window);
int 	key_event_listener(int key, t_window *window);
int		ft_close(void *param);
void	draw(t_map map, t_window window);

#endif
