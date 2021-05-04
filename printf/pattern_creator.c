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
	pattern_to_init->width = -1;
	pattern_to_init->accuracy = -1;
	pattern_to_init->type = 0;
}

void	set_field(char **str, va_list arg, int *ptr)
{
	if (**str == '*')
		*ptr = va_arg(arg, int);
	if (ft_isdigit(**str))
	{
		*ptr = ft_atoi(*str);
		*str = ft_strchr(*str, *ptr % 10 + '0');
	}
}
// note: str указывает на %
t_pattern	make_pattern(char **str, va_list arg)
{
	t_pattern	pattern;

	ft_memset(&pattern, 0, sizeof(t_pattern) - 1);
	init_pattern(&pattern);
	(*str)++;
	while (ft_strchr("cspdiuxX",**str) == NULL &&**str)
	{
		if ((**str == '-' ||**str == '0') && pattern.width == -1)
		{
			if (!(pattern.flag == '-' &&**str == '0'))
				pattern.flag =**str;
		}
		else if ((**str == '*' || ft_isdigit(**str)) && pattern.width == -1)
		{
			pattern.width = -2;
			set_field(&str, arg, &pattern.width);
		}
		else if (**str == '.')
		{
			pattern.accuracy = -2;
			++str;
			set_field(&str, arg, &pattern.accuracy);
		}
		(*str)++;
	}
	if (**str != '\0')
		pattern.type =**str;
	else
		init_pattern(&pattern);
	return (pattern);
}

//void	init_pattern(t_pattern *pattern_to_init, int init_data_arr[4],  size_t init_arr_size)
//{
//	if (pattern_to_init == NULL)
//		return ;
//	if (init_arr_size < 4 || init_data_arr == NULL)
//	{
//		if (init_data_arr == NULL)
//			init_arr_size = 0;
//		while (init_arr_size != 4)
//			init_data_arr[init_arr_size++] = 0;
//	}
//	pattern_to_init->flag = init_data_arr[0];
//	pattern_to_init->width = init_data_arr[1];
//	pattern_to_init->accuracy = init_data_arr[2];
//	pattern_to_init->type = init_data_arr[3];
//}

