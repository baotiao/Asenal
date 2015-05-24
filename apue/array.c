#include<stdio.h>
int a[5] = {1,2,3,4,5};
int main()
{
    int *p = a;
    for (; *p != '\0'; p++) {
        printf("The p is %d\n", *p);
    }
        printf("The p is %d\n", *p);
    return 0;
}
