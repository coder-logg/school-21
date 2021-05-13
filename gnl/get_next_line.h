#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE<0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE -1
#  endif
# endif

# include <unistd.h>
# include <stdlib.h>


int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy (char *dst, const char *src, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
