/*
    定义了三个数据结构 conn_queue_item,work_thread,dispatch_thread.
    conn_queue_item 只是存dispatch_thread accept 以后的描述符,然后
    dispatch_thread 将conn_queue_item 存入某一个work_thread.
    work_thread 真正负责work的thread.
    dispatch_thread 监听9877端口,并且将accept后的fd传给work_thread.
*/
#ifndef MAINH
#define MAINH

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

typedef struct conn_queue_item CQ;

struct conn_queue_item {
    int sfd;
};

struct WORK_THREAD {
    pthread_t thread_id;
    struct event_base *base;
    struct event notify_event;
    int notify_receive_fd;
    int notify_send_fd;
    struct conn_queue_item cq;
};
typedef struct WORK_THREAD wk_thread;

struct DISPATCH_THREAD {
    pthread_t thread_id;
    struct event_base *base;
};
typedef struct DISPATCH_THREAD dh_thread;

#endif
