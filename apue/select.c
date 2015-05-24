#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>


int main()
{
    fd_set rfds;
    struct timeval tv;
    int reval;
    char buf[10];
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    while (1) {
        reval = select(1, &rfds, NULL, NULL, &tv);
        printf("here it is  %d\n", reval);
        if (FD_ISSET(0, &rfds)) {
            if (read(0, buf, 10)) {
                printf("buf is %s\n", buf);
            }
        }
    }
    if (reval) {
        printf("Data is available now\n");
    } else {
        printf("No data whie five seconds\n");
    }
    return 0;
}


