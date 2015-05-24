#include<unistd.h>
#include<stdio.h>
#include<errno.h>

int main()
{
    char a[1000];
    int e = gethostname(a, 900);
    printf("%s\n", a);
    perror("erroooooooooooooo");
    return 0;
}
