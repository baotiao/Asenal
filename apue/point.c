#include<stdio.h>
int i = 5;
int *p = &i;
int j = 15;
int main()
{
    *p = 15;

    
    int *q = &j;
    (*q)++;
    
    printf("%d\n",*p);
    printf("%d\n", i);
    printf("%d\n", *q);
    printf("%d\n", j);
    return 0;
}
