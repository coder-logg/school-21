#include "printf.h"
#define accuracy pattern.accuracy
#define width pattern.width
#define pattern to_print.pattern
#define type to_print.type

char	*if_str(t_printable to_print, char *buf)
{
//	char	*src_end;
	char	*src_end;
	size_t	str_len;

	str_len = ft_strlen(type.string);
	if (accuracy < str_len && accuracy != -1)
	{
		src_end = type.string + accuracy;		//scr_end указываект на символ строки следующий за последним копируемым
		str_len = accuracy;
	}
	if (str_len < width)
	{
		if (pattern.flag == 0)
			ft_setmem(buf, ' ', width - str_len);
		if (pattern.flag == '-')
			ft_setmem(buf + str_len, ' ', width - str_len);
		if (pattern.flag == '0')
			ft_setmem(buf, '0', width - str_len);
	}
	return (buf);
}
