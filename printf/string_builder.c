#include "ft_printf.h"

int	make_string(t_printable to_print)
{
	char	*buf;
	size_t	res;

	buf = (char *)ft_calloc((max(digit_nbr(to_print.types.dec),
		max(to_print.pattern.accuracy, to_print.pattern.width))) + 7, sizeof(char));

	if (ft_strchr("cspdiuxX", to_print.pattern.type) == NULL)
		return 0;
	if (to_print.pattern.type == 's')
		res = if_str(buf, to_print);
	if (to_print.pattern.type == 'd' || to_print.pattern.type == 'i')
		res = if_dec(buf, to_print);
	if (to_print.pattern.type == 'c')
		res = if_chr(buf, to_print);
	if (to_print.pattern.type == 'p')
		res = if_ptr(buf, to_print);
	write(1, buf, res);
	//free(buf);
	return (res);
}
