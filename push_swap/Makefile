NAME	=	push_swap
LIBFT   =	libft/libft.a
SRCS	=	push.c push_swap.c reverse_rotate.c rotate.c swap.c sort.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	push_swap.h
LIBFTMAKE =	$(MAKE) -C libft/
CC		=	gcc

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

$(LIBFT):
	$(LIBFTMAKE)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $@ $(LIBFT) $(OBJS) -I $(HEADER)

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

re: fclean all

.PHONY:	all clean fclean re bonus