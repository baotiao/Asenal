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

static struct event_base *main_base;

void call_accept(int fd, short event, void *arg)
{
    fputs("a socket has come\n", stdout);
    struct sockaddr_in cliaddr;
    socklen_t clilen;
    int connfd;
    connfd = accept(fd, (struct sockaddr *) &cliaddr, &clilen);
    dispatch_new_thread(connfd);
}



int main()
{
    
    int listenfd, connfd;
    struct sockaddr_in cliaddr, servaddr;
    socklen_t clilen;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9877);
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listenfd, 10);

    struct event_base *mb;
    struct event ev;
    mb = event_init();
    event_set(&ev, listenfd, EV_READ | EV_PERSIST, call_accept, &ev);
    //event_base_set(main_base, &ev);
    event_add(&ev, NULL);
    printf("add the event\n");

    thread_init(10, mb);

    printf("block before accept\n");
    event_base_loop(mb, 0);

    return 0;
}
