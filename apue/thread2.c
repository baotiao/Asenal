#include<stdio.h>
#include<pthread.h>
#include<errno.h>

void *thr_fn1(void *arg)
{
    sleep(2);
    printf("This is 1 thread\n");
    pthread_exit((void *)2);
    return ((void *)2);
}

int main()
{
    int err;
    pthread_t tid1, tid2;
    void *tret;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);

    printf("%d\n", err);

    int b = 2;
    return 0;
}


