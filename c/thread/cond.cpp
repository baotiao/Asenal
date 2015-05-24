#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sankuai/timeused.h>

int32_t global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond  = PTHREAD_COND_INITIALIZER;


pthread_exit();
master; worker;

void * thread(void *arg)
{
    sleep(1);
    pthread_mutex_lock(&mutex);
    sleep(10);
    global = 2;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_mutex_lock(&mutex);
    sleep(5);
    global = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

pthread_cond_broadcast(cond);

int main()
{
    pthread_t tid;

    int32_t *p = (int32_t *)malloc(sizeof(int32_t));

    printf("before thread: global=%d\n", global);

    int32_t ret = pthread_create(&tid, NULL, thread, p);

    printf("waiting for global changed to 1\n");

    pthread_mutex_lock(&mutex);
    while (global != 1) {
        TimeUsed_t tu;
        tu.start();
        pthread_cond_wait(&cond, &mutex);
        tu.stop("cond_wait");
        printf("after wait: global=%d, %s\n", global, tu.string());
    }

    return 0;
}
