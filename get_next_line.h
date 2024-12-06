/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yant <yant@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:25:52 by yant              #+#    #+#             */
/*   Updated: 2024/12/06 18:08:15 by yant             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

int  ft_strlen(char *str);
char *ft_strchr(char *str);
char *ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);







#endif
