#include "printf.h"

static size_t	if_zerochr_and_minus_flag(char *buf, t_printable *to_print, char *pos)
{
	size_t	res;

	buf[0] = 0;
	if ((*to_print).pattern.width <= 1)
	{
		buf[1] = 0;
		res = 1;
	}
	else
	{
		pos[0] = 0;
		res = (*to_print).pattern.width;
	}
	return (res);
}

static size_t	if_zero(char *buf, t_printable to_print)
{
	size_t	res;
	char	*pos;

	res = 0;
	pos = ft_setmem(buf, get_fill_char(to_print.pattern),
			to_print.pattern.width);
	if (to_print.pattern.flag == '-')
		res = if_zerochr_and_minus_flag(buf, &to_print, pos);
	else if (to_print.pattern.width > 1)
	{
		pos[-1] = 0;
		pos[0] = 0;
		res = to_print.pattern.width;
	}
	else
	{
		buf[0] = 0;
		buf[1] = 0;
		res = 1;
	}
	return (res);
}

size_t	if_chr(char *buf, t_printable to_print)
{
	size_t	res;
	char	str[2];

	if (to_print.types.ui == 0)
		res = if_zero(buf, to_print);
	else
	{
		to_print.pattern.accuracy = -1;
		str[0] = to_print.types.ui;
		str[1] = 0;
		to_print.types.string = str;
		res = if_str(buf, to_print);
	}
	return (res);
}
