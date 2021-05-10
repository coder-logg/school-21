#include <stdio.h>
#include "printf.h"

int	ft_printf(const char *str, ...)
{
	t_printable printable;
	t_pattern	pattern;
	va_list		arg;
//	va_list		arg_copy;
	size_t		res_len;
	void *data;

	va_start(arg, str);
	printable = get_printable();
	res_len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			pattern = make_pattern((char **)&str, &arg);
			if (ft_strchr("cspdiuxX", pattern.type) != NULL)
			{
				data = NULL;
				data = va_arg(arg, void *);
				set_printable(&printable, pattern, data);
			}
			else
			{
				set_printable(&printable, pattern, &pattern.type);
				printable.pattern.type = 'c';
			}
			res_len += make_string(printable);
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

//#define input "%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d
//#define input1 "%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d
//#define input2 "%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d
//#define input3 "%X %u, %x %X, %u, %x, ", i, j, j, j, k, k
//#define input4 "%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j
//int main()
//{
//	int		a = -4; // a = 3 (accuracy), width = 0 , value = j = -12
//	int		b = 0;
//	char	c = 'a';
//	int		d = 2147483647;
//	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
//	int		i = 8;
//	int		j = -12;
//	int k = 6789789089786;
//	int		l = 0;
//	int		m = -12345678;
//	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";
//	a = -2;
//	int		index = 70;
//	a = -4;
////	printf(" --- Return : %d\n", printf("Simple input test"));
////	printf(" --- Return : %d\n", ft_printf("Simple input test"));
////	printf("\n%d\n", printf(input4));
////	printf("\n%d\n",ft_printf(input4));
//	printf("\n%d\n", printf(input3));
//	printf("\n%d\n",ft_printf(input3));
//}