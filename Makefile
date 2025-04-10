NAME 		= 		minitalk

NAME_SERVER = 		server
NAME_CLIENT =		client

CC 			=		cc

CFLAGS 		=		-Wall -Wextra -Werror

HEADER 		=		inc/minitalk.h	

LIBFT_A     = 		ft_printf.a

LIBFT_SRCS  = 		ft_printf/ft_point.c \
					ft_printf/ft_printf_util.c \
					ft_printf/ft_printf_util1.c \
					ft_printf/ft_printf.c \
					ft_printf/ft_atoi.c \

LIBFT_OBJS  = 		$(LIBFT_SRCS:.c=.o)

SRCS_SERVER = 		src/server.c
SRCS_CLIENT =		src/client.c

SERVER_COBJS= 		$(SRCS_SERVER:.c=.o)
CLIENT_COBJS=		$(SRCS_CLIENT:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A): $(LIBFT_OBJS)
	ar rcs $(LIBFT_A) $(LIBFT_OBJS)

$(NAME_SERVER): $(SERVER_COBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(SERVER_COBJS) $(LIBFT_A) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_COBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(CLIENT_COBJS) $(LIBFT_A) -o $(NAME_CLIENT)

clean:
	rm -rf $(CLIENT_COBJSC) $(SERVER_COBJS) $(LIBFT_OBJS)

fclean: clean
	rm -rf $(NAME_CLIENT)
	rm -rf $(NAME_SERVER)
	rm -rf $(LIBFT_A)

re: fclean all

.PHONY: fclean all clean re