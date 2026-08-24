#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd1, fd2;
    char buff[100];
    int n;

    fd1 = open("source.txt", O_RDONLY);
    fd2 = open("destination.txt", O_WRONLY | O_CREAT, 0644);

    n = read(fd1, buff, sizeof(buff));

    write(fd2, buff, n);

    printf("File copied successfully\n");

    close(fd1);
    close(fd2);

    return 0;
}
