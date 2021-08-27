#include "minitalk.h"

void	server_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	uc;
	static int				i;
	static int				count;

	(void)info;
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
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = server_handler;
	act.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid(), 1);
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		write(2, "sigcation error\n", 16);
		return (1);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		write(2, "sigcation error\n", 16);
		return (1);
	}
	while (1)
		;
	return (0);
}
