#include "printf.h"

char get_fill_char(t_pattern pattern)
{
	if (pattern.flag == '0' && pattern.accuracy != -1)
		return ('0');
	if (pattern.flag == '-' || pattern.flag == 0)
		return (' ');
	return (' ');
}

char	*get_start_pos(const t_printable *for_print, char *buf, int nbr_len, int field_len)
{
	char	*nbr_start;

	nbr_start = NULL;
	if (for_print->pattern.flag == '-')
		nbr_start = buf;
	else if (nbr_len < for_print->pattern.accuracy)
	{
		if (for_print->pattern.accuracy != field_len)
			nbr_start = buf + field_len - for_print->pattern.accuracy - 1;
		else
			nbr_start = buf;
	}
	else if (for_print->pattern.flag == '0')
	{
		if (for_print->pattern.accuracy == -1)
			nbr_start = buf;
		else
			nbr_start = buf + field_len - nbr_len;
	}
	else if (for_print->pattern.flag == 0)
		nbr_start = buf + field_len - nbr_len;
	return nbr_start;
}
char	*if_negative_nbr(t_printable *for_print, char *buf, int nbr_len, int field_len)
{
	char	*nbr_start;

	nbr_start = NULL;
	if (for_print->types.dec < 0)
	{
		nbr_start = get_start_pos(for_print, buf, nbr_len, field_len);
		nbr_start[0] = '-';
//		nbr_start++;
//		nbr_len--;
		if (for_print->pattern.accuracy > nbr_len)
			nbr_start = ft_setmem(nbr_start + 1, '0', for_print->pattern.accuracy - (nbr_len - 1));
		else if (for_print->pattern.flag == '0' && for_print->pattern.accuracy == -1 && field_len != nbr_len)
			nbr_start = ft_setmem(nbr_start + 1, '0', field_len - (nbr_len - 1));
		else
			{
				nbr_len--;
				nbr_start++;
			}
		itoa_withno_malloc(nbr_start, get_unsigned(for_print->types.dec));
		if (nbr_start + nbr_len != buf + field_len)
			nbr_start[nbr_len]= get_fill_char(for_print->pattern);
	}
	return (nbr_start);
}

void	if_positive_nbr(t_printable *for_print, char *buf, int nbr_len, int field_len)
{
	char	*nbr_start;

	nbr_start = NULL;
	if (for_print->types.dec >= 0)
	{
		nbr_start = get_start_pos(for_print, buf, nbr_len, field_len);
		if (for_print->pattern.accuracy > nbr_len)
			nbr_start = ft_setmem(nbr_start, '0', for_print->pattern.accuracy - nbr_len);
		else if (for_print->pattern.flag == '0' && for_print->pattern.accuracy == -1)
			nbr_start = ft_setmem(nbr_start, '0', field_len - nbr_len);
		itoa_withno_malloc(nbr_start, for_print->types.dec);
		if (nbr_start + nbr_len != buf + field_len)
			nbr_start[nbr_len]= get_fill_char(for_print->pattern);
	}
}
char	*if_dec(char* buf, t_printable to_print)
{
	int nbr_len;

	int		field_len;
	nbr_len = digit_nbr(to_print.types.dec);
	field_len = max(nbr_len, max(to_print.pattern.accuracy, to_print.pattern.width));
	if (field_len == to_print.pattern.accuracy && to_print.types.dec < 0)
		field_len++;
	nbr_len = digit_nbr(to_print.types.dec);
	ft_memset(buf, ' ', field_len);
	if (if_negative_nbr(&to_print, buf, nbr_len, field_len) == NULL)
		if_positive_nbr(&to_print, buf, nbr_len, field_len);
	buf[field_len] = 0;
	return (buf);
}
