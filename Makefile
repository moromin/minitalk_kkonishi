NAME		= minitalk
CLIENT		= client
SERVER		= server
C_SRCS		= client_main.c utils.c
S_SRCS		= server_main.c utils.c
# BONUS_SRCS	= 	
C_OBJS		= $(C_SRCS:%.c=%.o)
S_OBJS		= $(S_SRCS:%.c=%.o)
# BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(C_OBJS) $(S_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(CLIENT)
	$(CC) $(CFLAGS) $(S_OBJS) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(BONUS_OBJS) $(NAME)
	make bonus -C $(GNL_PATH)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_PATH) -lft -L$(GNL_PATH) -lgnl -o $(BONUS_NAME)

clean:
	rm -f $(C_OBJS) $(S_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
