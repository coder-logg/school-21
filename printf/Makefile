NAME    = libftprintf.a
SRCS    = $(wildcard *.c)
HEADERS = $(wildcard *.h)
LIBFT	= libft/libft.a
OBJS    = $(SRCS:.c=.o)
FLAGS   = -Wall -Wextra -Werror
PROJDIR = $(dir $(CURDIR))
LIBFTMAKE = $(MAKE) -C $(dir $(LIBFT))
CC		=	gcc

all: $(NAME)

%.o: %.c printf.h
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

$(LIBFT):
	$(LIBFTMAKE) printf

$(NAME): $(HEADERS) $(OBJS) $(NAME)($(OBJS)) $(LIBFT)

clean:
	rm -f $(OBJS) $(OBJBONUS)
	$(LIBFTMAKE) clean

fclean:	clean
	rm -f $(NAME)
	$(LIBFTMAKE) fclean

re: fclean all

#norm:
#	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BONUSFILES} ${HEADER}

.PHONY:     all clean fclean re