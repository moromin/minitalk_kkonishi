#include "minitalk.h"

void	args_check(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(2, "Error\n", 6);
		write(2, "Usage: ./client [PID] [string]\n", 31);
		exit(EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "Error\n", 6);
		write(2, "Invalid PID.\n", 13);
		exit(EXIT_FAILURE);
	}
}

void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < 8)
	{
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
		{
			write(2, "sending char error\n", 19);
			exit(EXIT_FAILURE);
		}
		i++;
		while (g_signal == 0)
			;
		g_signal = 0;
	}
}

void	client_handler(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signo == SIGUSR1)
		g_signal = SIGUSR1;
}

int	main(int argc, char *argv[])
{
	struct sigaction	act2;
	size_t				i;
	size_t				size;

	args_check(argc, argv);
	act2.sa_sigaction = &client_handler;
	act2.sa_flags = SA_SIGINFO;
	g_signal = 0;
	if (sigaction(SIGUSR1, &act2, NULL) != 0)
	{
		write(2, "sigcation error\n", 16);
		return (1);
	}
	size = ft_strlen(argv[2]);
	i = 0;
	while (i < size + 1)
		send_char((pid_t)ft_atoi(argv[1]), argv[2][i++]);
	return (0);
}
