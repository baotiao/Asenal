#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int f = open("/Users/czz/c/fork.c", O_RDONLY);
    //int f1 = open("/Users/czz/c/czz", O_RDONLY | O_CREATE | O_TRUNC);
    printf("%d\n", f);
    char buf[100];
    int n;
    while ((n = read(f, buf, 50) > 0)) {
        printf("%s\n", buf);
        printf("%d\n", n);
        //write(STDOUT_FILENO, buf, n);
        //if (write(STDOUT_FILENO, buf, n) != 0) {
        //    printf("error\n");
        //}
    }
    return 0;
}
