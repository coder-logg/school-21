NAME	=	minitalk
SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
OBJS	=	$(SERVER_SRC:.c=.o) $(CLIENT_SRC:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	minitalk.h
LIBFTMAKE =	$(MAKE) -C libft/
CC		=	gcc

all: libft client server

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

libft:
	$(LIBFTMAKE)

server:$(SERVER_OBJ)
	$(CC) -o $@ $(SERVER_OBJ) libft/libft.a

client:$(CLIENT_OBJ)
	$(CC) -o $@ $(CLIENT_OBJ) libft/libft.a

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean

fclean:
	rm -f client server $(OBJS)
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY:	all clean fclean re libft