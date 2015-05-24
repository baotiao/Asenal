#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <event.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include "csapp.h"
#include "xdebug.h"


int setnonblocking(int sockfd)
{
    if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK) == -1) {
        return -1;
    }
    return 0;
}


void str_echo(int& fd)
{
    char buf[10240];

    ssize_t nread;
    while (1) {
        nread = read(fd, buf, MAXLINE);
        printf("read size %d\n", nread);
        // printf("read buf %s\n", buf);
        if (nread == -1) {
            if ((errno == EINTR)) {
                printf("errno EINTR\n");
                continue;
            } else {
                printf("errno other\n");
                return ;
            }
        } else if (nread == 0) {
            printf("nread equal 0\n");
            close(fd); // close the fd to make it remove from the set of epoll
            return ;
        } else {
            break;
        }
    }
    return ;
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
    setnonblocking(listenfd);

    struct epoll_event ev, events[100];
    int kdfpd = epoll_create(100);
    ev.events = EPOLLIN;
    ev.data.fd = listenfd;
    int s = epoll_ctl(kdfpd, EPOLL_CTL_ADD, listenfd, &ev);
    int nfds;
    int tot = 0;
    
    for (;;) {
        nfds = epoll_wait(kdfpd, events, 100, 1000);
        if (nfds == -1) {
            perror("epoll_wait error");
            return -1;
        }
        // printf("nfds %d\n", nfds);
        for (int i = 0; i < nfds; i++) {
            // printf("fd %d %d\n", events[i].data.fd, events[i].events);
            if (events[i].data.fd == listenfd) {
                connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
                log_info("the accept fd is %d\n", connfd);
                setnonblocking(connfd);
                ev.events = EPOLLIN;
                ev.data.fd = connfd;
                epoll_ctl(kdfpd, EPOLL_CTL_ADD, connfd, &ev);
            } else {
                if (events[i].events & (EPOLLRDHUP | EPOLLERR | EPOLLHUP)) {
                    printf("timeup event\n");
                } else if (events[i].events & EPOLLIN) {
                    int fd = events[i].data.fd;
                    char buf[10240];

                    ssize_t nread;
                    while (1) {
                        nread = read(fd, buf, MAXLINE);
                        printf("read size %d\n", nread);
                        tot += nread;
                        printf("tot size %d\n", tot);
                        // printf("read buf %s\n", buf);
                        if (nread == -1) {
                            if ((errno == EINTR)) {
                                printf("errno EINTR\n");
                                continue;
                            } else {
                                printf("errno other\n");
                                break;
                            }
                        } else if (nread == 0) {
                            printf("nread equal 0\n");
                            close(fd); // close the fd to make it remove from the set of epoll
                                       // TODO: if don't close this fd, epoll will still cycle the fd
                                       // check why epoll return EPOLLIN but we
                                       // can't read anydata
                            break;
                        } else {
                            break;
                        }
                    }
                    break;
                    // str_echo((int)(events[i].data.fd));
                }
            }
        }
    }

    return 0;
}
