#include "ft_printf.h"

void	init_pattern(t_pattern *pattern_to_init)
{
	pattern_to_init->flag = 0;
	pattern_to_init->width = 0;
	pattern_to_init->accuracy = -1;
	pattern_to_init->type = 0;
}

long	set_field(char **str, va_list arg, long *ptr)
{
	if (**str == '.' && (*(*str + 1) == '*' || ft_isdigit(*(*str + 1))))
		(*str)++;
	if (**str == '*')
		*ptr = va_arg(arg, int);
	if (ft_isdigit(**str))
	{
		*ptr = ft_atoi(*str);
		*str = ft_strchr(*str, *ptr % 10 + '0');
	}
	return (*ptr);
}

void	check_negative(t_pattern *pattern)
{
	if (pattern->accuracy < 0)
		pattern->accuracy = -1;
	if (pattern->width < 0)
	{
		pattern->flag = '-';
		pattern->width *= -1;
	}
}

t_pattern	iter(char **str, va_list arg, t_pattern *pattern, char *indicators)
{
	if ((**str == '-' ||**str == '0') && !indicators[1])
	{
		indicators[0] = 1;
		if (!((*pattern).flag == '-' &&**str == '0'))
			(*pattern).flag =**str;
	}
	else if ((**str == '*' || ft_isdigit(**str)) && !indicators[2])
	{
		indicators[1] = 1;
		set_field(str, arg, &(*pattern).width);
	}
	else if (**str == '.')
	{
		(*pattern).accuracy = 0;
		indicators[2] = 1;
		set_field(str, arg, (long *)&(*pattern).accuracy);
	}
	return (*pattern);
}

char	check_patt_symbol(char c)
{
	if ((ft_strchr(".*-", c) != NULL || ft_isdigit(c)))
		return (1);
	return (0);
}

// note: str указывает на %
t_pattern	make_pattern(char **str, va_list arg)
{
	t_pattern	pattern;
	char		indicators[3];
	char		*start_tmp;

	ft_memset(&pattern, 0, sizeof(t_pattern));
	ft_memset(indicators, 0, 3);
	init_pattern(&pattern);
	(*str)++;
	start_tmp = *str;
	while (ft_strchr("cspdiuxX%", **str) == NULL && **str)
	{
		if (!check_patt_symbol(**str))
		{
			break;
		}
		pattern = iter(str, arg, &pattern, indicators);
		(*str)++;
	}
	if (**str != '\0')
	{
		pattern.type = **str;
		if (pattern.width < 0 || pattern.accuracy < 0)
			check_negative(&pattern);
	}
	else
		init_pattern(&pattern);
	return (pattern);
}
