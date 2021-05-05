#include "printf.h"
#include "short_names.h"

int	make_string(t_printable to_print)
{
	char	*buf;
	size_t	res;

	buf = malloc(patt_width + patt_accuracy + 1);
	if (ft_strchr("cspdiuxX", patt.type) == NULL)
		return 0;
	if (patt.type == 's')
		if_str(buf, to_print);
	if (patt.type == 'd')
		if_dec(buf, to_print);




	print_str(buf);
	res = ft_strlen(buf);
	free(buf);
	return (res);
}


