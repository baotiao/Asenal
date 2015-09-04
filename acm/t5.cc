#include <iostream>

int main()
{
    int a = 1;
    int &b = a;
    int *p = &a;
    printf("%d %d %d", b++, b, a);
    printf("%d\n", *p);
    return 0;
}
