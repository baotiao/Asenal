#include<stdio.h>

int main()
{
    int i = 50;
    int *pi = &i;
    int **ppi = &pi;
    printf("%d %d %d\n", ppi, *ppi, **ppi);
    printf("%d %d\n", &pi, &i);
    return 0;
}
