/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yant <yant@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:25:42 by yant              #+#    #+#             */
/*   Updated: 2024/12/06 18:25:29 by yant             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>


char *last_part(char *extra)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    j = 0;
    while (extra[i] != '\n' && extra[i] != '\0')
        i++;
    
    tmp = malloc(ft_strlen(extra) - i);
    if(extra[i] == '\n')
        i++;
    while (extra[i + j] != '\0')
    {
        tmp[j] = extra[i + j];
        j++;
    }
    tmp[j] = '\0';
    return(tmp);    
    
}

char *first_line(char *extra)
{
    int i;
    char *line;

    i = 0;
    while((extra[i] != '\n') && (extra[i] != '\0'))
        i++;
    line = malloc(i + 2);
    if(!line)
        return(free(extra),NULL);
    i=0;
    while (extra[i] != '\n' && extra[i] != '\0')
    {
        line[i] = extra[i];
        i++;
    }
    if(extra[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return(line);   
}

char *read_myfd(int fd,char *extra)
{
    char buffer[BUFFER_SIZE + 1];
    int readed;
    char    *tmp;

    readed = 1;
    while (readed != 0 && !ft_strchr(extra))
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        if(readed == -1)
            return(NULL);
        buffer[readed] = '\0';
        tmp = extra;
        extra = ft_strjoin(extra,buffer);
        free(tmp);
    }
    return(extra);
}

char *get_next_line(int fd)
{
    static char *extra;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    extra = read_myfd(fd,extra);
    //printf("%s\n", extra);
    line = first_line(extra);
    //printf("%s\n", line);
    extra = last_part(extra);
    //printf("%s", extra);
    return(line);
}