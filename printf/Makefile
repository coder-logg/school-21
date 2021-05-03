NAME    = libftprintf.a
SRCS    = *.c
LIBFT	= libft/libft.a
OBJS    = $(SRCS:.c=.o)
FLAGS   = -Wall -Wextra -Werror
HEADER  = libftprintf.h
PROJDIR = $(dir $(CURDIR))

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

${LIBFT}:
	cd $(dir $@) && $(MAKE) bonus

exex: $(LIBFT) $(NAME)

clean:
	rm -f $(OBJS) $(OBJBONUS)
	cd $(dir $(LIBFT)) && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd $(dir $(LIBFT)) && $(MAKE) fclean

re: fclean all

#norm:
#	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BONUSFILES} ${HEADER}

.PHONY:     all clean fclean re