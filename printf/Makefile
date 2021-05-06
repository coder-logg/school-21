NAME    = libftprintf.a
SRCS    = $(wildcard *.c)
HEADERS = $(wildcard *.h)
LIBFT	= g
OBJS    = $(SRCS:.c=.o)
FLAGS   = -Wall -Wextra -Werror
PROJDIR = $(dir $(CURDIR))
LIBFTMAKE = $(MAKE) -C libft/
CC		=	gcc

all: $(NAME)

%.o: %.c printf.h
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

${LIBFT}:
	${LIBFTMAKE} printf

$(NAME): $(HEADERS) $(OBJS) $(NAME)($(OBJS)) $(LIBFT)

clean:
	rm -f $(OBJS) $(OBJBONUS)
	$(LIBFTMAKE) clean

fclean:	clean
	rm -f $(NAME)

re: fclean all


.PHONY:     all clean fclean re