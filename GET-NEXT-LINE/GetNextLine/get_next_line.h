
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int search_str);
char	*ft_strdup(const char *str1);
void	fireforce(char **stored, char **allocated);
char	*ft_strjoin(char *s1, char *s2);
void	allocation(char **stored, char **allocated);
size_t	ft_strlen(const char *str);
char	*returned_line(char **stored, int readen);
int		ft_strcmp(char *s1, char *s2);

#endif