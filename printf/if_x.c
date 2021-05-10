#include "printf.h"

size_t	if_x(char *buf, t_printable to_print)
{
	char	*start_pos;
	int		field_len;
	int		nbr_len;


	nbr_len = nbr_len_hex(get_unsigned(to_print.types.ptr));
	field_len = max(nbr_len, max(to_print.pattern.accuracy, to_print.pattern.width));
	if (to_print.types.ptr == 0 && field_len == 1 && to_print.pattern.accuracy == 0)
	{
		buf[0] = 0;
		return (0);
	}
	ft_memset(buf, ' ', field_len);
	start_pos = get_start_pos(to_print, buf, nbr_len, field_len);
	if (to_print.pattern.accuracy >= nbr_len)
		start_pos = ft_setmem(start_pos, '0', to_print.pattern.accuracy - nbr_len);
	else if (to_print.pattern.flag == '0' && nbr_len < buf + field_len - start_pos)
		start_pos = ft_setmem(start_pos, '0', field_len - nbr_len);
	if (to_print.pattern.accuracy != 0)
	{
		itoa_hex(to_print.types.ptr, start_pos);
	}
	if (start_pos + nbr_len != buf + field_len)
		start_pos[nbr_len] = get_fill_char(to_print.pattern);
	buf[field_len + 1] = 0;
	if (to_print.pattern.type == 'X')
		for_each_chr_in_str(buf, (char (*)(char))ft_toupper);
	return (field_len);
}
