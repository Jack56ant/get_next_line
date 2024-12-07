/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yant <yant@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:15:21 by yant              #+#    #+#             */
/*   Updated: 2024/12/07 18:19:27 by yant             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

static char	*last_part(char *extra)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (extra[i] != '\0' && extra[i] != '\n')
		i++;
	if (!extra[i])
		return (free(extra), NULL);
	tmp = (char *)malloc(ft_strlen(extra) - i + 1);
	if (!tmp)
		return (NULL);
	i++;
	while (extra[i])
		tmp[j++] = extra[i++];
	tmp[j] = '\0';
	free(extra);
	return (tmp);
}

char	*first_line(char *extra)
{
	int		i;
	char	*line;

	i = 0;
	if (!extra[i])
		return (NULL);
	while (extra[i] != '\n' && extra[i] != '\0')
		i++;
	if (ft_strchr(extra))
		line = (char *)malloc(i + 2);
	else
		line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (extra[i] != '\0' && extra[i] != '\n')
	{
		line[i] = extra[i];
		i++;
	}
	if (extra[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_myfd(int fd, char *extra)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(extra) && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(extra), free(buffer), NULL);
		buffer[readed] = '\0';
		extra = ft_strjoin(extra, buffer);
	}
	free(buffer);
	return (extra);
}

char	*get_next_line(int fd)
{
	static char	*extra[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(extra[fd]);
		return (NULL);
	}
	extra[fd] = read_myfd(fd, extra[fd]);
	if (!extra[fd])
		return (NULL);
	line = first_line(extra[fd]);
	extra[fd] = last_part(extra[fd]);
	return (line);
}
