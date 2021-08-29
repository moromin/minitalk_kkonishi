#include "minitalk.h"

void	clear_buf(unsigned char *buf)
{
	size_t	i;

	i = 0;
	while (i < BUFSIZ)
		buf[i++] = 0;
}

void	print_message(unsigned char *buf, size_t *itr)
{
	size_t	size;

	size = *itr;
	write(1, buf, size + 1);
	*itr = 0;
}

void	server_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	uc;
	static int				i;
	static int				count;
	static unsigned char	buf[BUFSIZ];
	static size_t			itr;

	(void)context;
	if (count % 8 == 0)
		uc = 0;
	if (count % 8 == 0)
		i = 1;
	else
		i *= 2;
	count++;
	if (signo == SIGUSR2)
		uc += i;
	if (count % 8 == 0)
		buf[itr++] = uc;
	if (count % 8 == 0 && (count / 8 == BUFSIZ - 1 || uc == 0))
		print_message(buf, &itr);
	if (count / 8 == BUFSIZ - 1)
		clear_buf(buf);
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	act1;

	act1.sa_sigaction = server_handler;
	act1.sa_flags = SA_SIGINFO;
	write(1, "server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	if (sigaction(SIGUSR1, &act1, NULL) != 0)
	{
		write(2, "sigcation error\n", 16);
		return (1);
	}
	if (sigaction(SIGUSR2, &act1, NULL) != 0)
	{
		write(2, "sigcation error\n", 16);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
