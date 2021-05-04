#include "printf.h"
#include <stdio.h>

void	init_printable(t_printable *to_ini, t_pattern pattern, void *data)
{
	to_ini->pattern = pattern;
	to_ini->data = data;
}

t_printable	get_printable()
{
	t_printable res;

	ft_memset(&res, 0, sizeof(t_printable) - 1);
	res.data = NULL;
	res.set_all = init_printable;
	return (res);
}


//int main()
//{
//	printf("%017*d",7, 50);
//}
