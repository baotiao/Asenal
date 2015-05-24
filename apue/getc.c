#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int c;

    while ((c = getc(stdin))!= EOF) {
        if (putc(c, stdout) == EOF) {
            printf("output error");
        }
    }
    return 0;
}
