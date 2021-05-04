#ifndef PRINTF_H_
# define PRINTF_H_
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

//note %[флаги] [ширина] [.точность] [размер] тип
//note	  ||	   ||		||		   || 	   ||
//note   flags	 width	 accuracy     size    type
typedef struct s_pattern
{
	char	flag;
	int		width;
	int		accuracy;
	char	type;
}				t_pattern;

typedef struct s_printable
{
	t_pattern	pattern;
	void		*data;
	void		(* set_all)(struct s_printable *, t_pattern, void *);
}				t_printable;

t_pattern	make_pattern(char ** str, va_list arg);
t_printable	get_printable();
int			make_string(t_printable to_print);
#endif
