#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("/Users/czz/c/fork.c", O_RDONLY | O_NONBLOCK);
    printf("%d\n", fd);
    if (fd < 0) {
        perror("open fail\n");
        return -1;
    }
    char buf[100];
    while(read(fd, buf, 99) > 0) {
        printf("%s\n", buf);
    }
    return 0;
}

