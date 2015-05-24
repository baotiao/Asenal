#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("The Process Groupid is %d\n",getpgrp());
    printf("The pid is %d\n",getpid());
    printf("The ppid is %d\n",getppid());
    int t = setpgid(getpid(),985);
    printf("The Process Groupid is %d\n",getpgrp());
    printf("%d\n",t);
    exit(0);
}
