#include "ft_printf.h"

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

	i = 0;
	while (unbr > 0)
	{
		i++;
		unbr /= 16;
	}
	return (i);
}
char	*convert_to_hex(long nbr, char *dst)
{
	unsigned long	unbr;
	unsigned long	unbr_tmp;
	size_t			i;
	char			nbr_of_digits;


	unbr = get_unsigned(nbr);
	unbr_tmp = unbr;
	i = nbr_len_hex(unbr);
	nbr_of_digits = i;
	while (unbr_tmp > 0)
	{
		dst[--i] = get_hex(unbr_tmp % 16);
		unbr_tmp /= 16;
	}
	dst[(int)nbr_of_digits] = 0;
	return (dst);
}


size_t	if_ptr(char *buf, t_printable to_print)
{
//	buf
	(void) buf;
	(void)to_print;
	return (0);
}

//#include <stdio.h>
//int main()
//{
//	char dst[100];
//	long l = 9223372036854775807;
////	printf("%ld\n", l);
//	printf("%50.10p\n", l);
//	printf("%s\n", convert_to_hex(l,dst));
//}