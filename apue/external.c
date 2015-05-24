#include<stdio.h>
void fun()
{
    extern int c;
    printf("%d\n", c);
}
void fun1()
{
    printf("%d\n", c);
}
int main()
{
    fun();
    c = 1;
    c++;
    fun1();
    return 0;
}
