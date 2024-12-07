#include <fcntl.h>
#include <stdio.h>
int main()
{
    //int fd = open("text.txt", O_RDONLY);
    int fd = open("text.txt", O_RDONLY, 0777);
    printf("%d\n",fd);
    int fd1 = open("text3.txt",O_RDONLY, 0777);
printf("%d\n",fd1);
int fd4 = open("text4.txt", O_RDONLY, 0777);
    printf("%d\n",fd4);
int fd5 = open("text4.txt", O_RDONLY, 0777);
    printf("%d\n",fd5);
    int fd6 = open("text4.txt", O_RDONLY, 0777);
    printf("%d\n",fd6);
}