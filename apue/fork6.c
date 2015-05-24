#include<stdio.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        printf("error\n");
    } else if (pid == 0) {
        pid = fork();
        printf ("pid is %d\n", pid);
        if ((pid < 0)) {
            printf("second error\n");
        } else if (pid > 0) {
            //printf("here\n");
            //printf("second chidl %d\n", pid);
            exit(0);
        }
        sleep(2);
        printf("%d\n",pid);
        printf("The ppid is %d\n",getppid());
        exit(0);
    }
    int status;
    
    printf ("The father here pid is %d\n", pid);
    int t = waitpid(pid, NULL, 0);
    printf("The t is %d\n", t);
    exit(0);
}
