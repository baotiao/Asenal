#include <stdio.h>

void pp(int num)
{
    printf("the num is %d\n", num);
}

int main()
{
    void (*hello)(int);
    hello = pp;
    hello(10);
    return 0;
}
