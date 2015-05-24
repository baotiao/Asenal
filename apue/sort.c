#include<stdio.h>
#include<string.h>
int main()
{
    int a[5] = {3,2,4,1,5};
    sort(a, a+5);
    int i=0;
    for(i=0; i<5; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
