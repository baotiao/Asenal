#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MSG_TRY "try again\n"

int main(void)
{
    char buf[10];
    int fd, n;
    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if(fd<0) {
        perror("open /dev/tty");
        exit(1);
    }
    int flags;
    flags = fcntl(fd, F_GETFL, 0);
    flags |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flags);
    printf("here\n");
    while(1) {
        n = read(fd, buf, 10);
        printf("read buf %s\n", buf);
        write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
        sleep(1);
    }
    write(STDOUT_FILENO, buf, n);
    return 0;
}
