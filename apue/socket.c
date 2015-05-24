#include <stdio.h>
#include <sys/socket.h>
#include <time.h>
int main()
{
    //int a = socket(AF_INET, SOCK_DGRAM, 1001);
    int t = time(NULL);
    printf ("%d\n", t);
    return 0;
}
