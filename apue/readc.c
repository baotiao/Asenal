#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

#define BUFFSIZE 4096

int main()
{
    int n;
    char buf[BUFFSIZE];
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        fcntl(STDOUT_FILENO, O_NONBLOCK, 0);
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("write error");
        }
        printf("haha hei\n");
    }
    if (n<0) {
        printf("read error");
    }

}
