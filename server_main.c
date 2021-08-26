#include "minitalk.h"

volatile int	g_receive_signal;

static void	handle_signal(int signal)
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
	sigaction(SIGUSR2, &act, NULL);
}

static void	bit_to_string(t_vars *vars)
{
	if (vars->count % 8 == 0)
	{
		vars->uc = 0;
		vars->i = 1;
	}
	else
		vars->i *= 2;
	vars->count++;
	if (g_receive_signal == SIGUSR2)
		vars->uc += vars->i;
	if (vars->count % 8 == 0)
		write(1, &(vars->uc), 1);
}

// static void	receive_client_pid(t_vars *vars)
// {
// 	if (vars->count % 8 == 0)
// 	{
// 		vars->pid_client = 0;
// 		vars->uc = 0;
// 		vars->i = 1;
// 	}
// 	else
// 		vars->i *= 2;
// 	vars->count++;
// 	if (g_receive_signal == SIGUSR2)
// 		vars->uc += vars->i;
// 	if (vars->count % 8 == 0)
// 	{
// 		vars->pid_client = vars->pid_client * 10 + (vars->uc - '0');
// 		if (vars->uc == 0)
// 			vars->flag = 1;
// 	}
// 	if (vars->flag == 1)
// 		kill(vars->pid_client, SIGUSR1);
// }

int	main(void)
{
	t_vars	vars;
	pid_t	pid_server;

	pid_server = getpid();
	vars.count = 0;
	vars.flag = 0;
	ft_putnbr_fd(pid_server, 1);
	set_signal();
	while (1)
	{
		if (g_receive_signal == SIGUSR1 || g_receive_signal == SIGUSR2)
		{
			// if (vars.flag == 0)
			// 	receive_client_pid(&vars);
			// if (vars.flag == 1)
				bit_to_string(&vars);
		}	
		pause();
	}
	return (0);
}

	// TODO 
	// Receiving client pid and sending
	// while (1)
	// {
	// 	if (g_receive_signal == SIGUSR1 || g_receive_signal == SIGUSR2)
	// 		receive_client_pid();
	// 	// if ()
	// 	pause();
	// }