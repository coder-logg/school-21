#ifndef PRINTF_H_
# define PRINTF_H_
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

//note %[флаги] [ширина] [.точность] [размер] тип
//note	  ||	   ||		||		   || 	   ||
//note   flags	 width	 accuracy     size    type
typedef struct s_print_data
{
	char	flag;
	int		width;
	int		accuracy;
	int		size;
	char	type;
}				t_pattern;


#endif
