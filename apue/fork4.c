#include<stdio.h>
#include<sys/wait.h>
int main()
{
    int pid,npid;
    int status;
    if ((pid = fork()) == -1) {
        printf("error\n");
    } else if (pid == 0) {
        printf("I am child, And pid is %d\n", getpid());
        sleep(1);
        exit(7);
    } else {
        int t=wait(&status);
        printf("%d\n",t);
        printf("I am father,and status is %d\n", WTERMSIG(status));
    }
    exit(0);
}
