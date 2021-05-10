#include "printf.h"

unsigned int	get_bufsize(t_printable to_print)
{
	unsigned int	bufsize;

	bufsize = 100;
	if (to_print.pattern.type == 'd' || to_print.pattern.type == 'i')
		bufsize = max(digit_nbr(to_print.types.dec),
				max(to_print.pattern.accuracy, to_print.pattern.width)) + 2;
	if (to_print.pattern.type == 's' && to_print.types.string != NULL)
	{
		if (to_print.pattern.accuracy != -1)
			bufsize = to_print.pattern.accuracy + to_print.pattern.width + 2;
		else
			bufsize = to_print.pattern.width
				+ ft_strlen(to_print.types.string) + 2;
	}
	if (to_print.pattern.type == 'c')
		bufsize = to_print.pattern.width + 2;
	return (bufsize);
}

int	make_string(t_printable to_print)
{
	char	*buf;
	size_t	res;

	buf = (char *)ft_calloc(get_bufsize(to_print), sizeof(char));
	if (ft_strchr("cspdiuxX", to_print.pattern.type) == NULL)
		return (0);
	if (to_print.pattern.type == 's')
		res = if_str(buf, to_print);
	if (to_print.pattern.type == 'd' || to_print.pattern.type == 'i')
		res = if_dec(buf, to_print);
	if (to_print.pattern.type == 'c')
		res = if_chr(buf, to_print);
	if (to_print.pattern.type == 'p')
		res = if_ptr(buf, to_print);
	if (to_print.pattern.type == 'u')
	{
		to_print.types.dec = to_print.types.ui;
		res = if_dec(buf, to_print);
	}
	if (ft_strchr("xX", to_print.pattern.type) != NULL)
		res = if_x(buf, to_print);
	write(1, buf, res);
	free(buf);
	return (res);
}
