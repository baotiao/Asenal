#include<stdio.h>
#include<string.h>

int main()
{
    int a[10];
    int i;
    for (i=0; i<10; i++) {
        a[i] = i;
    }
    memset(a, 0, sizeof(a));
    for (i=0; i<10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}


