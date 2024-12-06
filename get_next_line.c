#include "get_next_line.h"


static int fazlası(char **fazla)
{
   char	*newline_ptr;

	newline_ptr = ft_strchar(*fazla ,'\n');
	if (newline_ptr && newline_ptr[1] != '\0')
	{
		*fazla = ft_strdup(newline_ptr + 1);
		if (!(*fazla))
            return (1);
	}
	else
		*fazla = NULL;
	return (0);
}
static char *get_line(char *artik_line)
{
	int		i;
	char	*line;

	i = 0;
	while (artik_line[i] && artik_line[i] != '\n')
		i++;
	if (artik_line[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, artik_line, i);
	line[i] = 0;
	return (line);
}

static char *read_myfd(int fd, char *artik)
{
    char buffer[BUFFER_SIZE + 1];
    int readed_fd = BUFFER_SIZE;
    char    *tmp;

    while (!ft_strchar(artik,'\n') && readed_fd != 0)
    {
        readed_fd = read(fd, buffer, BUFFER_SIZE);
        if (readed_fd == 0)
            break;
        if (readed_fd == -1)
        {
            free(artik);
            return (NULL);
        }

        buffer[readed_fd] = '\0';
        tmp = artik;
        artik = ft_strjoin(artik, buffer);
        free(tmp);
    }
    return (artik);
}

char *get_next_line(int fd)
{
    static char *artik = NULL;
    char    *line;
    char    *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    artik = read_myfd(fd, artik);
    if (!artik)
        return (NULL); 

    line = get_line(artik);
    if (!line)
	{
		free(artik);
		artik = NULL;
		return (NULL);
	}
    tmp = artik;
	if (fazlası(&artik))
	{
		free(line);
        line = NULL;
	}
	free(tmp);
	return (line);
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    char *line;
    line = get_next_line(fd);
    printf("Satır: %s\n", line);
    free(line);

    close(fd);
    return 0;
}
