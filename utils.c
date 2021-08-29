#include "minitalk.h"

static size_t	ft_strlen_uc(unsigned char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	ft_putstr(unsigned char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen_uc(s));
}
