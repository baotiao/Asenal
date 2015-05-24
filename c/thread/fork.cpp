#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int32_t global = 0;

int main()
{
    int32_t *p = (int32_t *)malloc(sizeof(int32_t));
    *p = 0;

    pid_t    pid = fork();

    if (pid == 0) {
        // 子进程
        global = 1;
        *p     = 1;
        sleep(3);
        printf("child: global=%d, *p=%d, pid=%d, &global=%ld, p=%ld\n", global, *p, getpid(), &global, p);
        exit(0);
    } else if (pid > 0) {
        // 父进程
        sleep(1);
        printf(": global=%d, *p=%d, pid=%d, &global=%ld, p=%ld\n", global, *p, getpid(), &global, p);
        exit(0);
    }
}
