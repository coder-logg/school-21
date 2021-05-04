#include <stdio.h>
#include "printf.h"

int ft_printf(const char *str, ...)
{
	t_printable printable;
	va_list		arg;

	va_start(arg, str);
	printable = get_printable();
	while (*str)
	{
		if (*str == '%')
		{
			printable.set_all(&printable, make_pattern((char **)&str, arg), arg);
			str = ft_strchr("cspdiuxX", *str);
		}
		str++;
	}
	return (0);
}

int main()
{
	ft_printf("lmmlml  %-0*.*s",5, 3);
}