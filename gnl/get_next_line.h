#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);

#endif

//		nl_chr_pos = NULL;
//		while (read_ret != 0 && nl_chr_pos == NULL)
//		{
//			nl_chr_pos = ft_memchr(buf, '\n', BUFFER_SIZE);
//			if (nl_chr_pos != NULL)
//			{
//				nl_chr_pos[0] = 0;
//				*line = ft_strjoin(NULL, buf);
//				nl_chr_pos[0] = '\n';
//				shift_buf_to_nl(buf);
//				break;
//			}
//			else
//			{
//				*line = ft_strjoin(*line, buf);
//			}
//			read_ret = read(fd, buf, BUFFER_SIZE);
//			ft_memset(buf + read_ret, 0, BUFFER_SIZE - read_ret);
//		}