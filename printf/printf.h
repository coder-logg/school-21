#ifndef PRINTF_H_
# define PRINTF_H_
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"


// Structures
//note %[флаги] [ширина] [.точность] [размер] тип
//note	  ||	   ||		||		   || 	   ||
//note   flags	 patt_width	 daccuracy     size    dtypes
typedef struct s_pattern
{
	char	flag;
	long	width;
	int		accuracy;
	char	type;
}				t_pattern;

typedef struct s_type
{
	char				*string;
	unsigned int		ui;
	unsigned long int	uli;
	int 				dec;
}				t_type;


typedef struct s_printable
{
	t_pattern	pattern;
	t_type		types;
	void		(* set)(struct s_printable *, t_pattern, void *);
}				t_printable;


// Prototypes
int			ft_printf(const char *str, ...);
t_pattern	make_pattern(char ** str, va_list arg);
t_printable	get_printable();
int			make_string(t_printable to_print);
char		*if_str(char *buf ,t_printable to_print);
char		*if_dec(char *buf, t_printable to_print);
void		print_str(char *str);
char		*fill_to_width(char* buf, char flag, size_t res_len, unsigned int width);

#endif
