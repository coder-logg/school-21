NAME	=	libft.a
SRCS	=	ft_bzero.c  ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memset.c ft_memcpy.c \
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strlcpy.c ft_strlen.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c \
			ft_atoi.c ft_strnstr.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_putstr_fd.c ft_putchar_fd.c \
			ft_putnbr_fd.c ft_putendl_fd.c ft_lstadd_front.c ft_lstnew.c\
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c itoa_withno_malloc.c max.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
HEADER	= libft.h

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

$(NAME): $(OBJS) $(NAME)($(OBJS))

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re