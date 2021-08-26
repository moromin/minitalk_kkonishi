#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
