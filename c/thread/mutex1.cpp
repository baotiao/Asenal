#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int32_t global = 0;

void addGlobal()
{
    for (int i = 0; i < 1000000000; i++)
        global++;
}

void * thread(void *arg)
{
    addGlobal();
    printf("in thread: global=%d\n", global);
    pthread_exit(0);
}

int main()
{
    pthread_t tid;

    int32_t *p = (int32_t *)malloc(sizeof(int32_t));

    printf("before thread: global=%d\n", global);

    int32_t ret = pthread_create(&tid, NULL, thread, p);

    addGlobal();

    printf("after thread: global=%d\n", global);
    sleep(1);
    return 0;
}
