#include <stdio.h>
#include "printf.h"

int	ft_printf(const char *str, ...)
{
	t_printable printable;
	va_list		arg;
	size_t		res_len;

	va_start(arg, str);
	printable = get_printable();
	res_len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			printable.set(&printable, make_pattern((char **)&str, arg), va_arg(arg, void *));
			res_len += make_string(printable);
		}
		else
		{
			write(1, str, 1);
			res_len++;
		}
		str++;
	}
	va_end(arg);
	return (res_len);
}

//#define input "%07d", -54
//
//int main()
//{
////	char *str ="%*.*s";
//	int r = 0;
//	r = printf(input);
//	printf("\n%d\n", r);
//	r = ft_printf(input);
//	printf("\n%d", r);
//}