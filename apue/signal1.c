#include<stdio.h>
#include<signal.h>
typedef void Sigfunc(int);

void sig_usr(int signo)
{
    if (signo == SIGUSR1) {
        printf("recive SIGURS1\n");
    } else if (signo == SIGUSR2) {
        printf("recive SIGURS2\n");
    } else {
        printf("other signal\n");
    }
}
int main()
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        printf("can't catch\n");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        printf("can't catch\n");
    }
    pause();
    printf("come here\n");
    return 0;
}
