#include "printf.h"

char	*fill_to_width(char* buf, char flag, size_t res_len, unsigned int width)
{
	char* pos;

	if (flag == 0)
		pos = ft_setmem(buf, ' ', width - res_len);
	if (flag == '-')
	{
		ft_setmem(buf + res_len, ' ', width - res_len);
		pos = buf;
	}
	if (flag == '0')
		pos = ft_setmem(buf, '0', width - res_len);
	return (pos);
}

char	*if_str(char *buf ,t_printable to_print)
{
	char	*pos;
	size_t	res_len;

	if (to_print.types.string == NULL || to_print.types.string == 0)
		to_print.types.string = "(null)";
	res_len = ft_strlen(to_print.types.string);
	if (to_print.pattern.accuracy < (int)res_len && to_print.pattern.accuracy != -1)
		res_len = to_print.pattern.accuracy;
	if (res_len < (size_t)to_print.pattern.width)
		pos = fill_to_width(buf, to_print.pattern.flag, res_len, to_print.pattern.width);
	else
		pos = buf;
	ft_memcpy(pos, to_print.types.string, res_len);
	if (res_len < (size_t)to_print.pattern.width && to_print.pattern.flag == '-')
		pos[to_print.pattern.width] = 0;
	else
		pos[res_len] = 0;
	return (buf);
}
