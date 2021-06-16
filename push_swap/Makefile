NAME	=	push_swap
SRCS	=	push.c push_swap.c reverse_rotate.c rotate.c swap.c sort.c utils.c \
 			utils_second.c sort_utils.c sort_short.c utils_third.c main_utils.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	push_swap.h
LIBFTMAKE =	$(MAKE) -C libft/
CC		=	gcc

all: libft $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

libft:
	$(LIBFTMAKE)

$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $@ $(OBJS) libft/libft.a

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY:	all clean fclean re libft