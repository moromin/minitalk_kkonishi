NAME		= minitalk
CLIENT		= client
SERVER		= server
COMMON		= utils_1.c utils_2.c
C_SRCS		= client_main.c $(COMMON)
S_SRCS		= server_main.c $(COMMON)
BONUS_C_SRCS	= client_main_bonus.c $(COMMON)
BONUS_S_SRCS	= server_main_bonus.c $(COMMON)
C_OBJS		= $(C_SRCS:%.c=%.o)
S_OBJS		= $(S_SRCS:%.c=%.o)
BONUS_C_OBJS	= $(BONUS_C_SRCS:%.c=%.o)
BONUS_S_OBJS		= $(BONUS_S_SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(C_OBJS) $(S_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(CLIENT)
	$(CC) $(CFLAGS) $(S_OBJS) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(BONUS_C_OBJS) $(BONUS_S_OBJS)
	$(CC) $(CFLAGS) $(BONUS_C_OBJS) -o $(CLIENT)
	$(CC) $(CFLAGS) $(BONUS_S_OBJS) -o $(SERVER)

clean:
	rm -f $(C_OBJS) $(S_OBJS) $(BONUS_C_OBJS) $(BONUS_S_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
