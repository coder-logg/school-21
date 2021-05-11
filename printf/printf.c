#include "printf.h"

size_t	parse_patt(va_list arg, const char **str)
{
	void		*data;
	t_printable	printable;
	t_pattern	pattern;

	pattern = make_pattern((char **)str, arg);
	if (ft_strchr("cspdiuxX", pattern.type) != NULL)
	{
		printable = get_printable();
		data = va_arg(arg, void *);
		set_printable(&printable, pattern, data);
	}
	else
	{
		set_printable(&printable, pattern, &pattern.type);
		printable.pattern.type = 'c';
	}
	return (make_string(printable));
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	size_t		res_len;

	res_len = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			res_len += parse_patt(arg, &str);
		}
		else
		{
			write(1, str, 1);
			res_len++;
			if (*str == '%' && *(str + 1) == '%')
				str++;
		}
		str++;
	}
	va_end(arg);
	return (res_len);
}
