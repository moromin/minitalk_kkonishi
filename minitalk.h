#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>
# include <signal.h>

# include "./libft/libft.h"
typedef struct s_vars
{
	size_t			count;
	size_t			i;
	unsigned char	uc;
}	t_vars;

// utils
void	ft_putstr(unsigned char *s, int fd);

#endif
