#include<stdio.h>

int *item[10];
int **ii;
int main()
{
    int *a = {{1,2,3},{4,5,6},{7,8,9}};
    int b[3][3] = {11,12,13,14,15,16,17,18,19};
    ii = &a;
    printf("ii is %d\n", *(ii + 1));
    return 0;
}
