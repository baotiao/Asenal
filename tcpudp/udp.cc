#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <event.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/epoll.h>
#include "csapp.h"
#include "xdebug.h"

typedef struct sockaddr SA;


int setnonblocking(int sockfd)
{
    if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK) == -1) {
        return -1;
    }
    return 0;
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9877);

    bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    setnonblocking(sockfd);

    struct epoll_event ev, events[100];
    int kdfpd = epoll_create(100);
    ev.events = EPOLLIN | EPOLLERR | EPOLLHUP;
    ev.data.fd = sockfd;
    int s = epoll_ctl(kdfpd, EPOLL_CTL_ADD, sockfd, &ev);
    int nfds;
    
    int n;
    char mesg[10240];
    socklen_t clilen = sizeof(cliaddr);
    int cnt = 0;
    char buf[10240];
    int tot = 0;
    for (;;) {
        nfds = epoll_wait(kdfpd, events, 100, 10000);
        printf("nfds %d\n", nfds);
        for (int i = 0; i < nfds; i++) {

            int fd = events[i].data.fd;
            if (events[i].events & EPOLLIN) {
                ssize_t nread = 1;
                while (1) {
                    nread = read(fd, buf, MAXLINE);
                    printf("%d\n", nread);

                    if (nread == -1) {
                        if ((errno == EINTR)) {
                            printf("errno EINTR\n");
                            continue;
                        } else {
                            printf("errno other\n");
                            break;
                        }
                    } else if (nread == 0){
                        close(fd);
                        break;
                    } else {
                        tot += nread;
                        printf("tot %d\n", tot);
                        break;
                    }
                }
            } else {
                printf("error come\n");
            }
        }
    }

    return 0;
}
