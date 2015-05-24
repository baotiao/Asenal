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
#include <arpa/inet.h>
#include "csapp.h"

typedef struct sockaddr SA;

uint64_t NowMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<uint64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;
}


void str_cli(int sockfd)
{
    int     n;
    int cnt = 1000;
    int len = 1000;
    char **strs = (char **)malloc(sizeof(char *) * cnt);
    for (int i = 0; i < cnt; i++) {
        strs[i] = (char *)malloc(sizeof(char) * len + 1);
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < len; j++) {
            strs[i][j] = (random() % 25) + 'a';
        }
        strs[i][len] = '\0';
    }
    uint64_t st, ed;
    st = NowMicros();
    for (int i = 0; i < cnt; i++) {
        int32_t nwritten = 0;
        nwritten = rio_writen(sockfd, strs[i], strlen(strs[i]));
        printf("nwritten %d\n", nwritten);
        usleep(2000000);
    }
    ed = NowMicros();
    printf("cost time %lld", ed - st);
}

int main(int argc, char **argv)
{

    if (argc != 2) {
        return -1;
    }
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9877);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    printf("connected success\n");
    str_cli(sockfd);
    return 0;
}
