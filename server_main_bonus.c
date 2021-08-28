#include "minitalk.h"

void	server_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	uc;
	static int				i;
	static int				count;

	(void)context;
	if (count % 8 == 0)
	{
		uc = 0;
		i = 1;
	}
	else
		i *= 2;
	count++;
	if (signo == SIGUSR2)
		uc += i;
	if (count % 8 == 0)
		write(1, &uc, 1);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		write(1, "ACK sending error\n", 18);
		exit(EXIT_FAILURE);
	}
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
