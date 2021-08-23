NAME	= philo
SRCDIR	=	./
SRCS	=	$(addprefix $(SRCDIR), main.c utils.c life.c time.c check_args.c)
OBJS	=	$(SRCS:.c=.o)
HEADER	=	$(addprefix $(SRCDIR), philo.h)
CC	=	gcc

all: $(NAME)

%.o: %.c
	cd $(@D) && $(CC) $(FLAGS) -c $(<F)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re