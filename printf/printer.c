#include "printf.h"

void	printer(char *str)
{
	write(1, str, ft_strlen(str));
}

int	make_string(t_printable to_print)
{
	char	type;

	type = to_print.pattern.type;
	if (ft_strchr("cspdiuxX",to_print.pattern.type) == NULL)
		return 0;

	if (to_print.pattern.type == 's')
		printer(to_print.data);
	return (1);
}
