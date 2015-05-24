#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buf[10];
    int fd;
    fd = open("header.c", O_RDONLY|O_CREAT);
    if (fd < 0) {
        perror("something must be wrong\n");
        exit(1) ;
    }
    int fdw = open("tmpout", O_RDWR|O_CREAT);
    if (fdw < 0) {
        perror("tmpout write error\n");
        exit(1);
    }
    int n, wn;
    while(1) {
//        scanf("%s", buf);
        n = read(fd, buf, 10);
        //printf("write %s\n", buf);
        wn = write(fdw, buf, strlen(buf)); 
        write(STDOUT_FILENO, "test block", 10);
        //sleep(1);
    }
    return 0;
}
