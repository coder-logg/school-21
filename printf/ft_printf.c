#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_printable printable;
	t_pattern	pattern;
	va_list		arg;
	size_t		res_len;

	va_start(arg, str);
	printable = get_printable();
	res_len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			pattern = make_pattern((char **)&str, arg);
			if (ft_strchr("cspdiuxX%", pattern.type) != NULL)
			{
				set_printable(&printable, pattern, va_arg(arg, void *));
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
//#define input3 "%1s, %1s, %1s, %1s, %1s", n, o, p, q, r
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
//	int		k = 123456789;
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
////	while (a < 5) //T187-213
////	{
////		printf("======================== %d ==============================\n", a);
////		printf("		|| --- Return : %d\n", printf(input));
////		ft_printf("		|| --- Return : %d\n\n", ft_printf(input));
////		printf("		|| --- Return : %d\n", printf(input1));
////		ft_printf("		|| --- Return : %d\n\n", ft_printf(input1));
////		printf("		|| --- Return : %d\n", printf(input2));
////		ft_printf("		|| --- Return : %d\n\n", ft_printf(input2));
////
////		a++;
////	}
//
////	while(a < 5) //T70-177
////	{
////		b = -2;
////		while (b < 5)
////		{
////			printf("======================== %d ==============================\n", index);
////			printf("		|| --- Return : %d\n", printf(input));
////			ft_printf("		|| --- Return : %d\n\n", ft_printf(input));
////			printf("		|| --- Return : %d\n", printf(input1));
////			ft_printf("		|| --- Return : %d\n\n", ft_printf(input1));
////			printf("		|| --- Return : %d\n", printf(input2));
////			ft_printf("		|| --- Return : %d\n\n\n", ft_printf(input2));
////			index++;
////			b++;
////		}
////		a++;
////	}
//	a = 19;
//	b = 14;
//	printf("--- Return : %d\n", printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r));
//	printf("--- Return : %d\n\n", ft_printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r));
//	printf("--- Return : %d\n", printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r));
//	printf("--- Return : %d\n\n", ft_printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r));
//	printf("--- Return : %d\n", printf("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r));
//	printf("--- Return : %d\n\n", ft_printf("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r));
//	printf("--- Return : %d\n", printf("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r));
//	printf("--- Return : %d\n\n", ft_printf("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r));
//}