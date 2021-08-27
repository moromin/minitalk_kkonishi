#include "minitalk.h"

// extern int	g_receive_signal;

// static void	bit_to_string(t_vars *vars)
// {
// 	if (vars->count % 8 == 0)
// 	{
// 		vars->uc = 0;
// 		vars->i = 1;
// 	}
// 	else
// 		vars->i *= 2;
// 	vars->count++;
// 	if (g_receive_signal == SIGUSR2)
// 		vars->uc += vars->i;
// 	if (vars->count % 8 == 0)
// 		write(1, &(vars->uc), 1);
// 	if (vars->uc == 0x04 && vars->count % 8 == 0)
// 	{
// 		vars->flag = 0;
// 		vars->pid_client = 0;
// 	}
// 	// printf("count:%zu, uc:%d, flag:%d\n", vars->count, vars->uc, vars->flag);
// }

// static void	receive_client_pid(t_vars *vars)
// {
// 	if (vars->count % 8 == 0)
// 	{
// 		vars->uc = 0;
// 		vars->i = 1;
// 	}
// 	else
// 		vars->i *= 2;
// 	vars->count++;
// 	if (g_receive_signal == SIGUSR2)
// 		vars->uc += vars->i;
// 	if (vars->uc == 0x04 && vars->count % 8 == 0)
// 	{
// 		if (kill(vars->pid_client, SIGUSR1) == -1)
// 			write(2, "Error\n", 6);
// 		vars->flag = 1;
// 		return ;
// 	}
// 	if (vars->count % 8 == 0)
// 		vars->pid_client = vars->pid_client * 10 + (vars->uc - '0');
// }

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
