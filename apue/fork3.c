#include <stdio.h>
int main()
{
    int fork_rv;
    printf("Before: my pid is %d\n",getpid());
    fork_rv = fork();
    if (fork_rv == -1) {
        perror("fork");
    } else if (fork_rv == 0){
        printf("I am the child process id is %d\n", getpid());
    } else {
        printf("I am the father process is %d\n", getpid()); 
    }
    return 0;
}
