#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

char buf[100000];

int main()
{
    int ntowrite, nwrite;
    char *ptr;
    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);

    fcntl(STDOUT_FILENO, F_SETFL, O_NONBLOCK);
    //fcntl(STDOUT_FILENO, O_NONBLOCK, 0);

    for (ptr = buf; ntowrite > 0; ) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }

    }
//    fcntl(STDOUT_FILENO, O_NONBLOCK, 1);
    return 0;
}
