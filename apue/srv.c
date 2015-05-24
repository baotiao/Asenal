#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
void str_echo(int sockfd)
{
    ssize_t n;
    char buf[1000];
again:
    while ((n = read(sockfd, buf, 1000)) > 0) { //读已经建立连接的socket的数据.
        fputs("a socket has come\n", stdout);
        write(sockfd, buf, n+3); // 写入数据
    }
    if (n < 0)
        exit(0);
}
int main()
{
    int listenfd, connfd;  //这两个分别是监听时候的链接,和accept建立以后的链接.
    pid_t childpid; //子进程的id.
    socklen_t clilen; 
    struct sockaddr_in cliaddr, servaddr; // 基于ipv4的套接字地址结构
    listenfd = socket(AF_INET, SOCK_STREAM,0); //返回一个socket描述符
    memset(&servaddr, 0, sizeof(servaddr));// 把这个servaddr地址初始化
    servaddr.sin_family = AF_INET; // 设置 adress family
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 设置套接字监听的地址为通配地址
    servaddr.sin_port = htons(9877); // 设置监听的端口号  
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    //将这个listenfd socket 描述符绑定到servaddr这个地址
    listen(listenfd, 10); //listenfd 这个socket端口开始监听
    for(; ; ) { // 一个死循环来server
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
        // 这里阻塞accept 等待 cli 连接. cli 连接成功会一个新的connfd,这个connfd就是通向客户端的socket描述符,往这个描述符写东西就可以送到客户端.
        if ((childpid = fork() == 0)) {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        fputs("i am parent\n", stdout);
        close(connfd);
    }
    return 0;
}
