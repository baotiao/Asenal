#include <stdio.h>

void foo(void)
{
    static int a;
    a++;
    printf("%d\n", a);
}

int main(void)
{
    static int a;
    foo();
    foo();
    foo();
    printf("%d\n", a);
    return 0;
}

