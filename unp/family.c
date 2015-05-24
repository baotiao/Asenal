#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
int sockfd_to_family(int sockfd)
{
    struct sockaddr_storage ss;
    socklen_t len;
    len = sizeof(ss);
    getsockname(sockfd, (struct sockaddr *) &ss, &len);
    return ss.ss_family;
}
