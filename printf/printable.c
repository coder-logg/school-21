#include "printf.h"
#include <stdio.h>

void	set_printable(t_printable *to_ini, t_pattern pattern, void *data)
{
	to_ini->pattern = pattern;
	if (pattern.type == 's')
		to_ini->types.string = (char *)data;
	else if (ft_strchr("cuXx", pattern.type) != NULL)
		to_ini->types.ui = (unsigned int)data;
	else if (pattern.type == 'd' || pattern.type == 'i')
		to_ini->types.dec = (int)data;
	else if (pattern.type == 'p')
		to_ini->types.ptr = (unsigned long)data;
	else
		to_ini->types.ui = *(unsigned int *)data;
}

t_printable	get_printable(void)
{
	t_printable	res;

	ft_memset(&res, 0, sizeof(t_printable));
	return (res);
}
