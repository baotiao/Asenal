#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <event.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include "main.h"


static dh_thread dispatch_thread;

static wk_thread *threads;

static int last_thread = -1;

void dispatch_new_thread(int fd)
{
    int tid = (last_thread + 1) % 10;
    wk_thread *thread = threads + tid;

    thread->cq.sfd = fd;
    write(thread->notify_send_fd, "", 1);
}


void thread_libevent_process(int fd, short which, void *arg)
{
    wk_thread *work_thread = arg;
    char unuse[1];
    if (read(fd, unuse, 1) != 1) {
        fprintf(stderr, "Can't read from libevent\n");
    }
    char buf[100];
    int n;
    n = read(work_thread->cq.sfd, buf, 100);
    write(work_thread->cq.sfd, buf, n);
}

void setup_thread(wk_thread *work_thread)
{
    work_thread->base = event_init();
    if (!work_thread->base) {
        fprintf(stdout, "Can't allocate event base\n");
        exit(1);
    }

    event_set(&work_thread->notify_event, work_thread->notify_receive_fd, EV_READ | EV_PERSIST, thread_libevent_process, work_thread);
    event_base_set(work_thread->base, &work_thread->notify_event);
    if (event_add(&work_thread->notify_event, 0) == -1) {
        fprintf(stdout, "Can't add libevent notify pipe\n");
        exit(1);
    }
}

void worker_libevent(void *arg)
{
    wk_thread *work_thread = arg;
    event_base_loop(work_thread->base, 0);
}

void create_worker(void *(*func)(void *), void *arg)
{
    pthread_t thread;
    pthread_attr_t attr;
    int ret;
    pthread_attr_init(&attr);

    if ((ret = pthread_create(&thread, &attr, func, arg)) != 0) {
        fprintf(stdout, "Can't create thread: %s\n", strerror(ret));
        exit(1);
    }
}


void thread_init(int t_num, struct event_base *main_base)
{
    dispatch_thread.base = main_base;
    dispatch_thread.thread_id = pthread_self();
    int i;
    threads = calloc(t_num, sizeof(wk_thread));
    if (!threads) {
        perror("Can't alloc so many thread\n");
        exit(1);
    }

    for (i = 0; i < t_num; i++) {
        int fds[2];
        if (pipe(fds)) {
            perror("can't pipe\n");
            exit(1);
        }
        threads[i].notify_receive_fd = fds[0];
        threads[i].notify_send_fd = fds[1];

        setup_thread(&threads[i]);
    }

    for (i = 0; i < t_num; i++) {
        create_worker(worker_libevent, &threads[i]);
    }

}
