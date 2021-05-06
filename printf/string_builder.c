#include "printf.h"

int	make_string(t_printable to_print)
{
	char	*buf;
	size_t	res;

	buf = malloc(max(digit_nbr(to_print.types.dec),
				max(to_print.pattern.accuracy, to_print.pattern.width)) + 2);
	if (ft_strchr("cspdiuxX", to_print.pattern.type) == NULL)
		return 0;
	if (to_print.pattern.type == 's')
		if_str(buf, to_print);
	if (to_print.pattern.type == 'd')
		if_dec(buf, to_print);




	print_str(buf);
	res = ft_strlen(buf);
	free(buf);
	return (res);
}


