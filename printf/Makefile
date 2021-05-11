NAME	=	libftprintf.a
SRCS	=	printf.c parser.c printable.c if_string.c \
			string_builder.c if_decimal.c if_pointer.c if_char.c if_x.c
HEADERS =	printf.h
LIBFT	=	g
OBJS	=	$(SRCS:.c=.o)
FLAGS	=	-Wall -Wextra -Werror
PROJDIR	=	$(dir $(CURDIR))
LIBFTMAKE =	$(MAKE) -C libft/
CC		=	gcc

all: $(NAME)

%.o: %.c printf.h
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

$(LIBFT):
	${LIBFTMAKE} printf

$(NAME): $(HEADERS) $(OBJS) $(NAME)($(OBJS)) $(LIBFT)

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY:	all clean fclean ref