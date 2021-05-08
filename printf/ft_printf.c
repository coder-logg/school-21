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

#define input "%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
#define input1 "%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
#define input2 "%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
#define input3 "%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	while (a < 5) //T34-69
	{
		printf("================== %d ====================\n", a);
		printf(input);
		printf("\n");
		ft_printf(input);
		printf("\n\n");
		printf(input1);
		printf("\n");
		ft_printf(input1);
		printf("\n\n");
		printf(input2);
		printf("\n");
		ft_printf(input2);
		printf("\n\n");
		printf(input3);
		printf("\n");
		ft_printf(input3);
		printf("\n\n");
		a++;
	}
}