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
	pid_t			pid_client;
	int				flag;
}	t_vars;

void	set_signal(void);

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);

#endif
