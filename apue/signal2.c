#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_alrm(int signo)
{

}
unsigned int sleep1(unsigned int nsecs)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return (nsecs);
    alarm(nsecs);
    printf("%d\n",pause());
    return (alarm(0));
}
int main()
{
    sleep1(3);
    pause();
    return 0;
}
