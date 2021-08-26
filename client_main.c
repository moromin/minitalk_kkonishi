#include "minitalk.h"

volatile int	g_receive_signal;

void	handle_signal(int signal)
{
	g_receive_signal = signal;
}

void	set_signal(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_handler = &handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
}

void	args_check(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(2, "Error\n", 6);
		write(2, "Usage: ./client [PID] <string>\n", 31);
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
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid_client;
	size_t	i;
	char	*str;
	size_t	size;

	i = 0;
	pid_client = getpid();
	str = ft_itoa(pid_client);
	if (!str)
		exit(EXIT_FAILURE);
	args_check(argc, argv);
	set_signal();
	// printf("clientPID:%d\n", pid_client);
	while (str[i])
	{
		send_char((pid_t)ft_atoi(argv[1]), str[i]);
		i++;
	}
	free(str);
	i = 0;
	size = ft_strlen(argv[2]);
	argv[2][size] = 0x04;
	while (i < size + 1)
	{
		send_char((pid_t)ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	while (1)
	{
		if (g_receive_signal == SIGUSR1)
		{
			write(1, "ACK received!\n", 14);
			break ;
		}
		pause();
	}
	return (0);
}
