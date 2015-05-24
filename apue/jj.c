#include "stdio.h"

void swap(int **p1, int **p2)
{
    int *p = *p1;
    *p1 = *p2;
    *p2 = p;
}

int main()
{
    int a = 1, b = 2;
    int *p1 = &a;
    int *p2 = &b;
    swap(p1, p2);

    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);
    return 0;
}
