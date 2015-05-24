#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

char buf1[] = "abcdfeghij";
char buf2[] = "ABCDEFGHIJ";
int main()
{
    int fd;
    if ((fd = creat("file.hole", O_RDWR)) < 0)
        printf("create erroe");
    if (write(fd, buf1, 10) != 10)
        printf("write error");
    if (lseek(fd, 40, SEEK_SET) == -1)
        printf("lseek error");
    if (write(fd, buf2, 10) != 10)
        printf("write buf2 error");
    return 0;
}
