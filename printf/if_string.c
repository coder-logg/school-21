#include "printf.h"
#include "short_names.h"

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

	if (dtypes.string == NULL || dtypes.string == 0)
		dtypes.string = "(null)";
	res_len = ft_strlen(dtypes.string);
	if (patt_accuracy < (int)res_len && patt_accuracy != -1)
		res_len = patt_accuracy;
	if (res_len < (size_t)patt_width)
		pos = fill_to_width(buf, patt.flag, res_len, patt_width);
	else
		pos = buf;
	ft_memcpy(pos, dtypes.string, res_len);
	if (res_len < (size_t)patt_width && patt.flag == '-')
		pos[patt_width] = 0;
	else
		pos[res_len] = 0;
	return (buf);
}
