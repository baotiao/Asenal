#include<stdio.h>
int main(int argc, char **argv)
{
    printf("Hello World\n");
    int i;
    printf("%d\n", argc);
    for (i=0; i<=argc; i++) {
        printf("%d %s\n", i, argv[i]);
    }
    return 0;
}
