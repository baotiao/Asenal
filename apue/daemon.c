#include <stdio.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>


int main()
{
    pid_t pid;

    if ((pid = fork()) < -1) {
        return -1;
    } else if (pid !=0 ) {
        return 0;
    }
    setsid();
    chdir("/");
    umask(0);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    FILE *fp;
    int fd;
    fp = fopen("/Users/czz/mydaemon.log", 'a');
//    fd = open("/Users/czz/mydaemon.log", O_CREAT | O_WRONLY | O_APPEND, 600);
//    char *buf="i am chenzongzhi\n";
//    while(1) {
//        write(fd, buf, strlen(buf) + 1);
//        sleep(1);
//    }
    while(1) {
        fputs("hei i'am chenzongzhi\n", stderr);
        sleep(1);
    }
    return 0;
}
