#include<stdio.h>
int glob = 6;
char buf[] = "a write to stdout\n";
int main()
{
    int var;
    int mypid = getpid();
    printf("Before My pid is %d\n",mypid);
    sleep(1);
    int nowp = fork();
    nowp = 1;
    printf("After: my pid is %d, fork() said %d\n",getpid(), nowp);
    return 0;
}
