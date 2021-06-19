NAME	=	minitalk
SRCS	=	utils.c
SERVER_SRC = server.c $(SRCS)
CLIENT_SRC = client.c $(SRCS)
OBJS	=	$(SERVER_SRC:.c=.o) $(CLIENT_SRC:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	minitalk.h
#LIBFTMAKE =	$(MAKE) -C libft/
CC		=	gcc

all: client server

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

server: $(SERVER_SRC:.c=.o)
	$(CC) -o $@ $^

client: $(CLIENT_SRC:.c=.o)
	$(CC) -o $@ $^

$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $@ $(OBJS) libft/libft.a

clean:
	rm -f  $(OBJS)
#$(LIBFTMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
#$(LIBFTMAKE) fclean

re: fclean all

.PHONY:	all clean fclean re libft