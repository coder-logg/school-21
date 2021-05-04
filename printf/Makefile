NAME    = libftprintf.a
SRCS    = $(wildcard *.c)
LIBFT	= libft/libft.a
OBJS    = $(SRCS:.c=.o)
FLAGS   = -Wall -Wextra -Werror
HEADER  = libftprintf.h
PROJDIR = $(dir $(CURDIR))
LIBFTMAKE = $(MAKE) -C $(dir $(LIBFT))

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADER) -c $<

(%.o): %.o
	ar rc $@ $<

$(LIBFT):
	$(LIBFTMAKE) bonus

$(NAME): $(LIBFT) $(OBJS) $(NAME)($(OBJS))

bonus: $(NAME) $(OBJBONUS) $(NAME)($(OBJBONUS))

exex: $(LIBFT) $(NAME)

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