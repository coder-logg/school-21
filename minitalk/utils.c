#include "minitalk.h"

void	error(const char *msg)
{
    write(2, msg, ft_strlen(msg));
    exit(1);
}
