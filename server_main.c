#include "minitalk.h"

static volatile sig_atomic_t	g_server_signal;

static void	clear_buf(unsigned char *buf)
{
	static volatile size_t	i;

	i = 0;
	while (i < BUFSIZ)
		buf[i++] = 0;
}

void	server_handler(int signo, siginfo_t *info, void *context)
{
	static volatile sig_atomic_t	count;

	(void)context;
	if (signo == SIGUSR1)
		g_server_signal = SIGUSR1;
	if (signo == SIGUSR2)
		g_server_signal = SIGUSR2;
	count++;
	kill(info->si_pid, SIGUSR1);
	if (count == 8)
		count = 0;
}

static void	server_loop(void)
{
	static volatile unsigned char	uc;
	static volatile sig_atomic_t	count;
	static volatile unsigned char	buf[BUFSIZ];
	static volatile sig_atomic_t	itr;

	while (g_server_signal == 0)
		usleep(1);
	if (g_server_signal == SIGUSR2)
		uc |= (1 << count);
	if (g_server_signal == SIGUSR1)
		uc &= ~(1 << count);
	count++;
	if (count % 8 == 0)
		buf[itr++] = uc;
	if (count % 8 == 0 && (itr == BUFSIZ - 1 || uc == 0))
	{
		ft_putstr((unsigned char *)buf, 1, (int)itr);
		count = 0;
		if (itr == BUFSIZ - 1)
			clear_buf((unsigned char *)buf);
		if (uc == 0)
			write(1, "\n", 1);
		itr = 0;
	}
	g_server_signal = 0;
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = server_handler;
	act.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
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
		server_loop();
	return (0);
}
