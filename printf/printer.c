#include "printf.h"
#define BUFSIZE 100

void	printer(char *str)
{
	write(1, str, ft_strlen(str));
}
