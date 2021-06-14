NAME	=	push_swap
LIBFT   =	libft/libft.a
SRCS	=	push.c push_swap.c reverse_rotate.c rotate.c swap.c sort.c utils.c \
 			utils_second.c sort_utils.c sort_short.c utils_third.c main_utils.c
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

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY:	all clean fclean re