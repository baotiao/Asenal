#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
void str_cli(FILE *fp, int sockfd)
{
    char sendline[1000], recvline[1000];
    while(fgets(sendline, 1000, fp) != NULL) {
        write(sockfd, sendline, strlen(sendline));
        if (read(sockfd, recvline, 100) == 0)
            printf("server terminated\n");
        fputs(recvline, stdout);
    }
}int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9877);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    str_cli(stdin, sockfd);
    return 0;
}

