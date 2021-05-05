#include "printf.h"

void	print_str(char *str)
{
	write(1, str, ft_strlen(str));
}
