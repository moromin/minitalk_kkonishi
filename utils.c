#include "minitalk.h"

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * 10 + (str[i] - '0')) / 10 != res)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- > 0)
		*p++ = 0;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[30];
	int		count;

	count = 0;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	while (n)
	{
		if (n >= 0)
			num[count] = '0' + (n % 10);
		else
			num[count] = '0' - (n % 10);
		n /= 10;
		count++;
	}
	while (count > 0)
		write(fd, &num[count-- - 1], 1);
	write(fd, "\n", 1);
}

static char	*len_malloc(int n, int *len)
{
	char	*str;
	int		count;

	count = 1;
	if (n < 0)
		count++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		count++;
	}
	str = malloc(sizeof(char) * (count + 2));
	if (str == NULL)
		return (NULL);
	*len = count;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = 0;
	str = len_malloc(n, &len);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[len] = 0x04;
	str[len + 1] = '\0';
	while (n)
	{
		if (n > 0)
			str[--len] = '0' + (n % 10);
		else
			str[--len] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}
