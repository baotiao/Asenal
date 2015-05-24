#include<stdio.h>
#include<signal.h>
static void sig_quit(int signo) 
{
    printf("catch the signal\n");

}
int main()
{
    if (signal(SIGQUIT, sig_quit) == SIG_ERR) {
        printf("can't catch SIGQUIT\n");
    }
    pause();
    return 0;
}
