#include "minitalk.h"

void	ft_putstr(unsigned char *s, int fd, int size)
{
	if (!s)
		return ;
	write(fd, s, size);
}
