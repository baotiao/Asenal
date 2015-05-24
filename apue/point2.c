#include<stdio.h>
int main()
{
    int i = 5;
    int *p = &i;
    int **q = &p;
    printf("p is %d, q is %d\n", *p, **q);
}
