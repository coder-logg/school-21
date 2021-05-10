#ifndef PRINTF_H_
# define PRINTF_H_
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

// Structures
//note %[флаги] [ширина] [.точность] [размер] тип
//note	  ||	   ||		||		   || 	   ||
//note   flags	 width	 accuracy    size    types
typedef struct s_pattern
{
	char	flag;
	long	width;
	int		accuracy;
	char	type;
}				t_pattern;

typedef struct s_type
{
	char			*string;
	unsigned int	ui;
	long int		ptr;
	long			dec;
}				t_type;

typedef struct s_printable
{
	t_pattern	pattern;
	t_type		types;
}				t_printable;

// Prototypes
int			ft_printf(const char *str, ...);
t_pattern	make_pattern(char **str, va_list *arg);
t_printable	get_printable();
int			make_string(t_printable to_print);
size_t		if_str(char *buf, t_printable to_print);
size_t		if_dec(char *buf, t_printable to_print);
size_t		if_ptr(char *buf, t_printable to_print);
size_t		if_chr(char *buf, t_printable to_print);
char		get_fill_char(t_pattern pattern);
void		set_printable(t_printable *to_ini, t_pattern pattern, void *data);
char		*get_start_pos(t_printable for_print, char *buf, int nbr_len,
				int field_len);
size_t		itoa_hex(long nbr, char *dst);
size_t		nbr_len_hex(unsigned long unbr);
char		get_hex(unsigned char digit);
size_t		if_x(char *buf, t_printable to_print);

#endif
