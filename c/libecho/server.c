#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <event.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>

typedef struct sockaddr * SA;
struct event_base *main_base;

void str_echo(int fd, short event, void *arg)
{
    char buf[100];
    int n;

    n = read(fd, buf, 100);
        fputs("a socket has come\n", stdout);
        write(fd, buf, n);
    if (n < 0) {
        return ;
    }
    return ;
}

void call_accept(int fd, short event, void *arg)
{
    printf("come in a new accept\n");
    struct sockaddr_in cliaddr;
    socklen_t clilen;
    int connfd;
    connfd = accept(fd, (struct sockaddr *) &cliaddr, &clilen);
    printf("accept from cliaddr\n");
    char buf[100];
//    read(fd, buf, 100);
    //str_echo(connfd);
//    printf("%d\n", (void *)base);
//    struct event read_ev;
//    //fcntl(connfd, F_SETFL, O_NONBLOCK);
//    event_set(&read_ev, connfd, EV_READ, str_echo, &read_ev);
//    //event_base_set(main_base, &read_ev);
//    event_add(&read_ev, NULL);
    
//    event_base_loop(base, 0);
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


    main_base = event_init();
    struct event ev;
    event_set(&ev, listenfd, EV_READ | EV_PERSIST, call_accept, &ev);
    //event_base_set(main_base, &ev);
    event_add(&ev, NULL);
    event_base_loop(main_base, 0);
    printf("block before accept\n");
    printf("after event_dispatch\n");
    return 0;
}
