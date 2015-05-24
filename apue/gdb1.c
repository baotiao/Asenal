#include<stdio.h>
int fun(int a)
{
    printf("%d\n", a);
    int m = 0;
    int i;
    for (i=0; i<10; i++) {
        m++;
    }
    printf("%d\n", m);
}
int main()
{
    fun(3);
    printf("The answer is %d\n", fun(10));
    return 0;
}
