#include<stdio.h>
void print(char *str)
{
    printf("hello %s\n", str);
}
int main()
{
    void (*f)(char *) = print;
    f("heihei");
    return 0;
}
