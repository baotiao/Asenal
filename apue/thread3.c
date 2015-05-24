#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t iMutex = PTHREAD_MUTEX_INITIALIZER;
int ans = 0;

void *threadDo(void *arg)
{
    printf("come into the threadDo function\n");
    //int num = *((int *)arg);
    //printf("num %d\n", num);
    pthread_mutex_lock(&mutex);
    ans++;
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

int main()
{
    int numThread = 2;
    pthread_t *ptr = (pthread_t *)malloc(sizeof(pthread_t) * numThread);

    
    printf("numThread is %d\n", numThread);
    for (int i = 0; i < numThread; i++) {
        printf("address ptr is %d\n", &ptr[i]);
        pthread_create(&ptr[i], NULL, threadDo, NULL);
    }

    //for (int i = 0; i < numThread; i++) {
    //    pthread_join(ptr[i], NULL);
    //}

    free(ptr);
    printf("after initial is %d\n", ans);
    return 0;
}
