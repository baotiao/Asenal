#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    //time_t t = time(NULL);
    printf("%ld %ld\n", t.tv_sec, t.tv_usec);
    return 0;
}
