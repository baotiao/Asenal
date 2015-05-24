#include<pthread.h>
#include<errno.h>
#include<stdio.h>

void *thr_fn1(void *arg)
{
    sleep(10);
    printf("thread 1 returning\n");
    return ((void *)1);
}

void *thr_fn2(void *arg)
{
    printf("thread 2 returning\n");
    return ((void *)2);
}

int main()
{
    int err;
    pthread_t tid1, tid2;
    void *tret;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err !=0 ) {
        printf("%s\n", strerror(err));
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err !=0 ) {
        printf("%s\n", strerror(err));
    }

    err = pthread_join(tid1, &tret);

    err = pthread_join(tid2, &tret);
    if (err != 0) {
        printf("%s\n", strerror(err));
    }
    printf("thread exit code %d\n", (int)tret);
    return 0;
}
    
