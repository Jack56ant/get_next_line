/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ulti.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yant <yant@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:25:45 by yant              #+#    #+#             */
/*   Updated: 2024/12/06 18:28:40 by yant             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
int  ft_strlen(char *str)
{
    int i;

    i=0;
    while (str[i] != '\0')
    {
        i++;
    }
    return(i);
}

char *ft_strchr(char *str)
{
  
    if(!str)
        return(NULL);
    while (*str)
    {
       if(*str == '\n')
        return(str);
        str++;
    }
    return(NULL);
}

char *ft_strjoin(char *s1, char *s2)
{ 
    char *tmp;
    int i;
    int j;

    i=0;
    j=0;
   
    if(!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }
    if(!s1 || !s2)
        return(NULL);
    tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!tmp)
        return(NULL);
    while (s1[i])
    {
        tmp[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        tmp[i + j] = s2[j];
        j++;
    }
    tmp[i + j] = '\0';
    free(s1);
    return(tmp);
}


