NAME	=	fdf
SRCDIR	=	src/
SRCS	=	$(addprefix $(SRCDIR), fdf.c fdf_utils.c listeners.c read_map.c prepare_window.c draw.c math_oper.c)
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
FRAEMWORKS=-framework OpenGL -framework AppKit
HEADER	=	$(addprefix $(SRCDIR), fdf.h)
LIBFTMAKE =	$(MAKE) -C libft/
MLXMAKE =	$(MAKE) -C minilibx/
CC		=	gcc

all: libft/libft.a minilibx/libmlx.a $(NAME)

%.o: %.c $(HEADER)
	cd $(@D) && $(CC) $(FLAGS) -c $(<F)

libft/libft.a:
	@$(LIBFTMAKE)

minilibx/libmlx.a:
	@$(MLXMAKE)

$(NAME): libft/libft.a minilibx/libmlx.a $(OBJS)
	$(CC) -o $@ $(OBJS) libft/libft.a minilibx/libmlx.a $(FRAEMWORKS)

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean
	rm -f minilibx/*.o

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean
	rm -f minilibx/*.o
	rm -f libmix.a

re: fclean all

.PHONY:	all clean fclean re