#include <iostream>
#include <stdio.h>


int main()
{
    printf("%d\n", sizeof("\x00\x00\x00\x00\x00\x00"));
    return 0;
}
