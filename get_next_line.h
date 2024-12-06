#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H



#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 5
#endif

#include <stdio.h>  
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchar(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);



#endif