#include "printf.h"
#include "short_names.h"

char	get_fill_char(char flag)
{
	if (flag == '0')
		return ('0');
	if (flag == '-' || flag == 0)
		return (' ');
}

char	*if_dec(char *buf, t_printable to_print)
{
	int		nbr_len;
	char	*nbr_start;
	int		nbr;
	char	fill_char;

	nbr_len = digit_nbr(dtypes.dec);
	if (patt.flag == '-')
		nbr_start = buf;
	else
		nbr_start = buf + patt_width - nbr_len;
	if (patt_accuracy != -1 && patt.flag == '0')
		patt.flag = 0;
	fill_char = get_fill_char(patt.flag);
	if (patt_width > nbr_len)
	{
		ft_memset(buf, fill_char, patt_width);
		nbr = dtypes.dec;
		if (dtypes.dec < 0 && patt.flag == '0')
		{
			buf[0] = '-';
			nbr = get_unsigned(dtypes.dec);
			nbr_start = buf + patt_width - nbr_len;
		}
		itoa_withno_malloc(nbr_start, nbr)[nbr_len] = fill_char;
		buf[patt_width] = 0;
	}
	else
		itoa_withno_malloc(nbr_start, dtypes.dec);
	return (buf);
}
