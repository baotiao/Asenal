#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#define SA struct sockaddr
void str_cli(FILE *fp, int sockfd)
{
    char sendline[1000], recvline[1000];
    while(fgets(sendline, 1000, fp) != NULL) {
        write(sockfd, sendline, strlen(sendline));
        if (read(sockfd, recvline, 1000) == 0)
            printf("server terminated\n");
        fputs(recvline, stdout);
    }
}

int main(int argc, char *argv[])
{
    printf("here\n");
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9877);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    printf("%d\n", servaddr.sin_addr.s_addr);
    char s[100];
    char *p;
    p = s;
    inet_ntop(AF_INET, &servaddr.sin_addr, p, sizeof(s));
    printf("%s\n", p);
    printf("here2\n");
    struct sockaddr_storage ss;
    socklen_t len;
    len = sizeof(ss);
    int cans = connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
    printf("cans %d\n", cans);
        int ans = getsockname(sockfd, (struct sockaddr *) &ss, &len);
        printf("%d\n", ans);
        printf("%d\n", ss.ss_family);
    printf("here3\n");
    str_cli(stdin, sockfd);
    return 0;
}
