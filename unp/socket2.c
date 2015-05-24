#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
typedef struct sockaddr SA


int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    socklen_t len;
    len = sizeof(server_addr);
    if (getsockname(sockfd, (SA *)


