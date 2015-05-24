#include<stdio.h>
int (*sum)(int *a, int *b)
{
    int *c = a;
    return *c;
}
int main()
{
    int a=2,b=4;
    //int p = *sum(&a, &b);
    int p=1;
    printf("%d\n", p);
    return 0;
}
