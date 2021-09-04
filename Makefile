NAME		= minitalk
CLIENT		= client
SERVER		= server
C_SRCS		= client_main.c
S_SRCS		= server_main.c
BONUS_C_SRCS	= client_main_bonus.c
BONUS_S_SRCS	= server_main_bonus.c
C_OBJS		= $(C_SRCS:%.c=%.o)
S_OBJS		= $(S_SRCS:%.c=%.o)
BONUS_C_OBJS	= $(BONUS_C_SRCS:%.c=%.o)
BONUS_S_OBJS	= $(BONUS_S_SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft/

all: $(NAME)

$(NAME): $(C_OBJS) $(S_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(C_OBJS) -L$(LIBFT_PATH) -lft -o $(CLIENT)
	$(CC) $(CFLAGS) $(S_OBJS) -L$(LIBFT_PATH) -lft -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# bonus: $(BONUS_C_OBJS) $(BONUS_S_OBJS)
# 	$(CC) $(CFLAGS) $(BONUS_C_OBJS) -L$(LIBFT_PATH) -lft -o $(CLIENT)
# 	$(CC) $(CFLAGS) $(BONUS_S_OBJS) -L$(LIBFT_PATH) -lft -o $(SERVER)

bonus: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(C_OBJS) $(S_OBJS) $(BONUS_C_OBJS) $(BONUS_S_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
