#include "minitalk.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	kill((pid_t)ft_atoi(argv[1]), SIGSEGV);
	return (0);
}
