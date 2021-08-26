#include "minitalk.h"

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

	i = 0;
	pid_client = getpid();
	str = ft_itoa(pid_client);
	if (!str)
		exit(EXIT_FAILURE);
	args_check(argc, argv);
	// while (1)
	// {
	// 	send_char((pid_t)ft_atoi(argv[1]), str[i]);
	// 	if (str[i] == 0)
	// 		break ;
	// 	i++;
	// }
	// i = 0;
	while (argv[2][i])
	{
		send_char((pid_t)ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	free(str);
	return (0);
}
