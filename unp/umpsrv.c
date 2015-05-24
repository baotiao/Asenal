#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
void str_echo(int sockfd)
{
    fputs("a socket has come\n", stdout);
    ssize_t n;
    char buf[1000];
again:
    while ((n = read(sockfd, buf, 1000)) > 0) {
        //fputs("a socket has come\n", stdout);
        write(sockfd, buf, n);
    }
    if (n < 0)
        exit(0);
}
int main()
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    struct sockaddr_in nameaddr;
    listenfd = socket(AF_INET, SOCK_STREAM,0);
    int a[10];
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9877);
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
        struct sockaddr_storage ss;
        socklen_t len;
        len = sizeof(ss);
        int ans = getsockname(connfd, (struct sockaddr *) &ss, &len);
        printf("%d\n", ans);
        printf("%d\n", ss.ss_family);
        printf("%d\n", len);
    
    listen(listenfd, 10);
    for(; ; ) {
        clilen = sizeof(cliaddr);
        //printf("come here\n");
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
        printf("%d\n", connfd);
        struct sockaddr_storage ss;
        socklen_t len;
        len = sizeof(ss);
        int ans = getsockname(connfd, (struct sockaddr *) &ss, &len);
        printf("%d\n", ans);
        printf("%d\n", ss.ss_family);
        printf("%d\n", len);
        fputs("a socket has come\n", stdout);
        if ((childpid = fork()) == 0) {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        fputs("i am parent\n", stdout);
        close(connfd);
    }
    return 0;
}
