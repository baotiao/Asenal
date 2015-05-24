#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int32_t global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond  = PTHREAD_COND_INITIALIZER;


void * thread(void *arg)
{
    pthread_cond_wait(&cond, &mutex);
}

void * thread1(void *arg)
{
    pthread_cond_wait(&cond, &mutex);
}

int main()
{
    pthread_t tid;

    int32_t *p = (int32_t *)malloc(sizeof(int32_t));

    printf("before thread: global=%d\n", global);

    int32_t ret = pthread_create(&tid, NULL, thread, p);

    printf("waiting for global changed to 1\n");

    pthread_mutex_lock(&mutex);
    while (global != 1) {
        printf("after wait: global=%d\n", global);
    }

    return 0;
}
