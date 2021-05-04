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
		if (*str == '%' && *(str + 1) != '%')
		{
			printable.set(&printable, make_pattern((char **)&str, arg), va_arg(arg, void *));
			make_string(printable);
		}
		else
			write(1, str, 1);
		str++;
	}
	return (0);
}

int main()
{
	char *str ="%*.*s";
//	printf(str,  5, 3, "abcde");
	ft_printf(str,  5, 3, "abcde");
//	ft_printf(str , 10, -30, "-40", 4);

}