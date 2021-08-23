NAME	=	fdf
	SRCDIR	=	src/
	SRCS	=	$(addprefix $(SRCDIR),  main.c utils.c key_listeners.c read_map.c draw.c draw_line.c rotation.c \
					menu.c color.c init.c)
	OBJS	=	$(SRCS:.c=.o)
	HEADER	=	$(addprefix $(SRCDIR), fdf.h)
BONUSDIR	=	src_bonus/
SRCS_BONUS =  $(addprefix $(BONUSDIR),  main_bonus.c utils_bonus.c key_listeners_bonus.c read_map_bonus.c \
 				draw_bonus.c draw_line_bonus.c rotation_bonus.c menu_bonus.c color_bonus.c init_bonus.c)
BONUS_OBJS =	$(SRCS_BONUS:.c=.o)
BONUS_HEADER	=	$(addprefix $(BONUSDIR), fdf_bonus.h)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
FRAEMWORKS	=	-framework OpenGL -framework AppKit
LIBFTMAKE =	$(MAKE) -C libft/
MLXMAKE =	$(MAKE) -C minilibx_macos/
CC		=	gcc

all: libft/libft.a minilibx_macos/libmlx.a $(NAME)

%.o: %.c
	cd $(@D) && $(CC) $(FLAGS) -c $(<F)

libft/libft.a:
	@$(LIBFTMAKE)

minilibx_macos/libmlx.a:
	@$(MLXMAKE)

$(NAME): $(OBJS) $(HEADER)
	$(CC) -o $@ $(OBJS) libft/libft.a minilibx_macos/libmlx.a $(FRAEMWORKS)

bonus: libft/libft.a minilibx_macos/libmlx.a $(BONUS_OBJS) $(BONUS_HEADER)
	$(CC) -o $(NAME:=_bonus) $(BONUS_OBJS) libft/libft.a minilibx_macos/libmlx.a $(FRAEMWORKS)

clean:
	rm -f  $(OBJS) $(BONUS_OBJS)
	$(LIBFTMAKE) clean
	$(MLXMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS) $(BONUS_OBJS) $(NAME:=_bonus)
	$(LIBFTMAKE) fclean
	$(MLXMAKE) clean

re: fclean all

.PHONY:	all clean fclean re libft/libft.a