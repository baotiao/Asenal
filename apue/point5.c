#include<stdio.h>
#include<string.h>
void swap1(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    char s[10] = "hehehaha";
    printf("%lu\n", (sizeof(s)));
    int a=5,b=10;
    swap1(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
