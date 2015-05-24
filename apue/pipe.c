#include<stdio.h>
#include<unistd.h>
int main()
{
    int fd[2];
    char str[20];
    int n;
    pid_t pid;
    pipe(fd);
    if ((pid=fork()) < 0) {
        printf("error\n");
    } else if (pid == 0) {
        sleep(1);
        write(fd[1], "Hello World\n", 12);
        read(fd[0], str, 2);
        printf("parent\n");
    } else {
        n = read(fd[0], str, 12);
        printf("%s\n", str);
    }
    return 0;
}
