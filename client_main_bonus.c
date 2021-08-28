#include "minitalk.h"

size_t	g_count;

void	args_check(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(2, "Error\n", 6);
		write(2, "Usage: ./client [PID] [string]\n", 31);
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) < 0)
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
		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
		{
			write(2, "sending char error\n", 19);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	client_handler(int signo, siginfo_t *info, void *context)
{
	static size_t	count;

	(void)info;
	(void)context;
	if (signo == SIGUSR1)
		count++;
	if (count == g_count)
	{
		write(1, "ACK received!\n", 14);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act2;
	size_t				i;
	size_t				size;

	args_check(argc, argv);
	act2.sa_sigaction = client_handler;
	act2.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act2, NULL) != 0)
	{
		write(2, "sigcation error\n", 16);
		return (1);
	}
	size = ft_strlen(argv[2]);
	g_count = size * 8;
	i = 0;
	while (i < size)
		send_char((pid_t)ft_atoi(argv[1]), argv[2][i++]);
	while (1)
		pause();
	return (0);
}
