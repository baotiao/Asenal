#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <queue>

using namespace std;

vector<pthread_t *> g_workers;
queue<char>       g_tasks;
pthread_mutex_t   mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t    cond = PTHREAD_COND_INITIALIZER;

void * worker(void * arg)
{
    int id = *(int *)&arg;

    while (true) {
        pthread_mutex_lock(&mutex);

        while (g_tasks.empty()) {
            pthread_cond_wait(&cond, &mutex);
        }

        char c = g_tasks.front();
        g_tasks.pop();
        printf("worker %d, task=%c, thread_id=%lu\n", id, c, (uint64_t)pthread_self());

        pthread_mutex_unlock(&mutex);
    }

}

void createWorkers(int num)
{
    pthread_t * ptr;

    for (int i = 0; i < num; i++) {
        ptr = new pthread_t;
        pthread_create(ptr, NULL, worker, (void *)i);
        g_workers.push_back(ptr);
    }
    return;
}

int main()
{
    int c;

    createWorkers(3);
    printf(">>>");
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            continue;
        pthread_mutex_lock(&mutex);
        g_tasks.push(c);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    exit(0);
    return 0;
}
