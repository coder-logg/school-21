NAME	=	push_swap
LIBFT   =	libft/libft.a
SRCS	=	push.c push_swap.c push_swap.h reverse_rotate.c rotate.c swap.c
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
	$(CC) -o $@ $(LIBFT) $(OBJS)

cclean:
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