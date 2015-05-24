#include<stdio.h>
#include<errno.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>

int main()
{
    int s = socket(AF_INET, SOCK_STREAM, 0); 
    if (s == -1) {
        perror("socke\n");
    }
    perror("errortooooooo\n");

    char *str = strerror(1);
    int i;
    for (i = 0; i < 10; i++) {
        printf("%s\n", strerror(i));
    }
    printf("%d\n", errno);
    return 0;
}
