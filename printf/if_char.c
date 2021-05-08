
#include "ft_printf.h"

size_t if_chr(char *buf, t_printable to_print)
{
	size_t	res;
	to_print.pattern.accuracy = -1;
	char str[2];
	str[0] = to_print.types.ui;
	str[1] = 0;
	to_print.types.string = str;
	res = if_str(buf, to_print);
	if (to_print.types.ui == 0)
	{
//		if (to_print.pattern.flag == '-')
//		{
//			buf[0] = 0;
//		}
//		else if (to_print.pattern.width > 1)
//			buf[to_print.pattern.width - 1] = 0;
//		write(1, str, 2);
		return (1);
	}
	return (res);
}
