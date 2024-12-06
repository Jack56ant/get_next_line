#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd = open("dosya.txt", O_RDONLY);
    char *str;
    char *str2;

    str = get_next_line(fd);
    printf("%s", str);
        free(str);
     str2 = get_next_line(fd);
    printf("%s", str);
    free(str2);
}