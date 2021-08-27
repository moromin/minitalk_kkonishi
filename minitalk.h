#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>
# include <signal.h>

typedef struct s_vars
{
	size_t			count;
	size_t			i;
	unsigned char	uc;
}	t_vars;

// utils
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char **s1, char *s2, size_t size1, size_t size2);

#endif
