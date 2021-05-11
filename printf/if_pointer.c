#include "printf.h"

char	get_hex(unsigned char digit)
{
	if (digit <= 9 && digit >= 0)
		return (digit + '0');
	else if (digit > 9 && digit <= 15)
		return (digit % 10 + 'a');
	else
		return (-1);
}

size_t	nbr_len_hex(unsigned long unbr)
{
	size_t	i;

	if (unbr == 0)
		return (1);
	i = 0;
	while (unbr > 0)
	{
		i++;
		unbr /= 16;
	}
	return (i);
}

size_t	itoa_hex(unsigned long nbr, char *dst)
{
	unsigned long	unbr;
	unsigned long	unbr_tmp;
	size_t			i;
	size_t			nbr_len;

	unbr = nbr;
	unbr_tmp = unbr;
	i = nbr_len_hex(unbr);
	dst[i] = 0;
	nbr_len = i;
	while (i-- > 0)
	{
		dst[i] = get_hex(unbr_tmp % 16);
		unbr_tmp /= 16;
	}
	return (nbr_len);
}

size_t	if_ptr(char *buf, t_printable to_print)
{
	char	*start_pos;
	int		field_len;
	int		nbr_len;
	int		accur;

	nbr_len = nbr_len_hex(to_print.types.ptr);
	accur = to_print.pattern.accuracy;
	if (to_print.pattern.accuracy != -1)
		to_print.pattern.accuracy += 2;
	field_len = max(nbr_len + 2, max(to_print.pattern.accuracy,
				to_print.pattern.width));
	ft_memset(buf, ' ', field_len);
	start_pos = get_start_pos(to_print, buf, nbr_len + 2, field_len);
	start_pos[0] = '0';
	start_pos[1] = 'x';
	start_pos += 2;
	if (accur > nbr_len)
		start_pos = ft_setmem(start_pos, '0', accur - nbr_len);
	itoa_hex(to_print.types.ptr, start_pos);
	if (start_pos + nbr_len != buf + field_len)
		start_pos[nbr_len] = get_fill_char(to_print.pattern);
	buf[field_len + 1] = 0;
	return (field_len);
}
