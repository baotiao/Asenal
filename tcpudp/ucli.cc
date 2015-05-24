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
#include "xdebug.h"
typedef struct sockaddr SA;
#define MAXLINE 1024

uint64_t NowMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<uint64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int     n;
    int cnt = 1;
    int len = 10;
    char **strs = (char **)malloc(sizeof(char *) * cnt);
    for (int i = 0; i < cnt; i++) {
        strs[i] = (char *)malloc(sizeof(char) * len + 1);
    }
    for (int i = 0; i < cnt; i++) {
        snprintf(strs[i], sizeof(strs[i]), "%d", i);
        // for (int j = 0; j < len; j++) {
        //     strs[i][j] = (random() % 25) + 'a';
        // }
        // strs[i][len] = '\0';
    }
    uint64_t st, ed;
    st = NowMicros();
    int totn = 0;
    int nwrite;
    
    int ctime = 1;
    while (ctime--) {
        for (int i = 0; i < cnt; i++) {
            nwrite = sendto(sockfd, strs[i], strlen(strs[i]), 0, pservaddr, servlen);
            printf("%s\n", strs[i]);
            totn += nwrite;
        }
        log_info("totn %d", totn);
        // sleep(1);
    }
    ed = NowMicros();
    close(sockfd);
    printf("cost time %lld\n", ed - st);
    printf("totn %d", totn);
}

#define COMMAND_HEADER_LENGTH 4
#define COMMAND_CODE_LENGTH 4

bool BuildObuf(char* obuf, int32_t opcode, const int packet_len)
{
    //obuf_ = (char *)realloc(obuf_, sizeof(char) * (packet_len + COMMAND_HEADER_LENGTH + COMMAND_CODE_LENGTH));

    uint32_t code_len = COMMAND_CODE_LENGTH + packet_len;
    uint32_t u;

    u = htonl(code_len);
    memcpy(obuf, &u, sizeof(uint32_t));
    u = htonl(opcode);
    memcpy(obuf + COMMAND_CODE_LENGTH, &u, sizeof(uint32_t));
    // memcpy(obuf + COMMAND_HEADER_LENGTH + COMMAND_CODE_LENGTH, packet, packet_len);

    return true;
}

void send_pb(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    // char *obuf = (char *)malloc(sizeof(char) * 1000);
    char obuf[11] = "hahahahaha";
    char w[100];
    BuildObuf(w, 1, sizeof(obuf));
    memcpy(w + 4 + 4, obuf, sizeof(obuf));
    for (int i = 0; i < 10; i++) {
        sendto(sockfd, w, 4 + 4 + sizeof(obuf), 0, pservaddr, servlen);
    }

}

int main(int argc, char **argv)
{

    int     sockfd;
    struct sockaddr_in servaddr;

    if(argc != 2) {
        return -1;
        // err_quit("usage: udpcli <IPaddress>");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9221);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int default_buf;
    socklen_t optlen = sizeof(default_buf);

    int res = getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &default_buf, &optlen);
    log_info("default_buf %d", default_buf);

    // int buflen = 3 * 1024 * 1024;
    // if (setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &buflen, sizeof(buflen)) == -1) {
    //     log_err("set socket opt error");
    // }

    // if (setsockopt(sockfd, SOL_SOCKET, SO_SNDLOWAT, &buflen, sizeof(buflen)) == -1) {
    //     log_err("set socket opt error");
    // }

    // dg_cli(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));
    send_pb(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

    return 0;
}
