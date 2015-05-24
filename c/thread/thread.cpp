#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int32_t global = 0;

void * thread(void *arg)
{
    global = 1;
    int32_t *p = (int32_t *)arg;
    *p = 1;
    printf("in subthread: global=%d, *p=%d\n", global, *p);
    pthread_exit(0);
}

int main()
{
    pthread_t tid;

    int32_t *p = (int32_t *)malloc(sizeof(int32_t));
    *p = 0;

    printf("before: global=%d, *p=%d\n", global, *p);

    int32_t ret = pthread_create(&tid, NULL, thread, p);
    printf("pid=%ld\n", tid);

    sleep(1);

    printf("after: global=%d, *p=%d\n", global, *p);
    return 0;
}
