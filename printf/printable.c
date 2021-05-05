#include "printf.h"
#include <stdio.h>

void	set_printable(t_printable *to_ini, t_pattern pattern, void *data)
{
	to_ini->pattern = pattern;
	if (pattern.type == 's')
		to_ini->types.string = (char *)data;
	if (ft_strchr("cuxX", pattern.type) != NULL)
		to_ini->types.ui = (unsigned int)data;
	if (pattern.type == 'd')
		to_ini->types.dec = (int)data;
	if (pattern.type == 'p')
		to_ini->types.uli = (unsigned long)data;
}

t_printable	get_printable()
{
	t_printable res;

	ft_memset(&res, 0, sizeof(t_printable) - 1);
	res.set = set_printable;
	return (res);
}
