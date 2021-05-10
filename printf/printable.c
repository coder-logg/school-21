#include "printf.h"
#include <stdio.h>

void	set_printable(t_printable *to_ini, t_pattern pattern, void *data)
{
	to_ini->pattern = pattern;
	if (pattern.type == 's')
		to_ini->types.string = (char *)data;
	else if (ft_strchr("cu", pattern.type) != NULL)
		to_ini->types.ui = (unsigned int)data;
	else if (pattern.type == 'd' || pattern.type == 'i')
		to_ini->types.dec = (int)data;
	else if (ft_strchr("pXx", pattern.type) != NULL)
		to_ini->types.ptr = (long)data;
//	else
//		to_ini->types.ui = *(unsigned int *)data;
}

t_printable	get_printable(void)
{
	t_printable	res;

	ft_memset(&res, 0, sizeof(t_printable));
	return (res);
}
