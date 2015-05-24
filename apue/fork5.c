#include<stdio.h>
#include<sys/wait.h>
int main()
{
    int pid,npid;
    if ((pid = fork()) == -1) {
        printf("error!");
    } else if (pid == 0) {
        sleep(10);
        printf("first child\n");
    } else {
        if ((npid = fork() == 0)) {
            sleep(1);
            printf("second child\n");
        } else {
            int status;
            int t = wait(&status);
            printf("parent status=%d t=%d\n", WEXITSTATUS(status), t);
        }
    }
    exit(1);
}
