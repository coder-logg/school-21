#include "printf.h"

t_pattern	*new_pattern()
{
	t_pattern *res;

	res = malloc(sizeof(t_pattern));
	ft_memset(res, 0, sizeof(t_pattern) - 1);
	return (res);
}

void	init_pattern(t_pattern *pattern_to_init)
{
	pattern_to_init->flag = 0;
	pattern_to_init->width = 0;
	pattern_to_init->accuracy = -1;
	pattern_to_init->type = 0;
}

void	set_field(char **str, va_list arg, long *ptr)
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
}

void check_patt(t_pattern* pattern, char ind[3])
{
	if (pattern->accuracy < 0 && ind[2])
		pattern->accuracy = 0;
	if (pattern->width < 0)
	{
		pattern->flag = '-';
		pattern->width *= -1;
	}
}

// note: str указывает на %
t_pattern	make_pattern(char **str, va_list arg)
{
	t_pattern	pattern;
	char		indicators[3];

	ft_memset(&pattern, 0, sizeof(t_pattern));
	ft_memset(indicators, 0, 3);
	init_pattern(&pattern);
	(*str)++;
	while (ft_strchr("cspdiuxX",**str) == NULL &&**str)
	{
		if ((**str == '-' ||**str == '0') && !indicators[1])
		{
			indicators[0] = 1;
			if (!(pattern.flag == '-' &&**str == '0'))
				pattern.flag =**str;
		}
		else if ((**str == '*' || ft_isdigit(**str)) && !indicators[2])
		{
			indicators[1] = 1;
			set_field(str, arg, &pattern.width);
		}
		else if (**str == '.')
		{
			indicators[2] = 1;
			set_field(str, arg, (long *)&pattern.accuracy);
		}
		(*str)++;
	}
	if (**str != '\0')
	{
		pattern.type = **str;
		check_patt(&pattern, indicators);
	}
	else
		init_pattern(&pattern);
	return (pattern);
}


