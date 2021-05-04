#include "printf.h"

int	make_string(t_printable to_print)
{
	char	type;
	char	*buf;
	int 	curpos;

	buf = malloc(to_print.pattern.width + to_print.pattern.accuracy);

	if (ft_strchr("cspdiuxX",to_print.pattern.type) == NULL)
		return 0;
	if (to_print.pattern.type == 's')
		if_str(to_print, buf);

	return (1);
}


