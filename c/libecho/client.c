#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <event.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

typedef struct sockaddr * SA;

void str_cli(FILE *fp, int sockfd)
{
    char sendline[100], recvline[100];
    while (fgets(sendline, 100, fp) != NULL) {
        write(sockfd, sendline, strlen(sendline));
        if (read(sockfd, recvline, 100) == 0) {
            printf("server terminated\n");
        }
        fputs(recvline, stdout);
    }
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9877);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    printf("connected success\n");
    str_cli(stdin, sockfd);
    return 0;
}

