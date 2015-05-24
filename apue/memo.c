#include<stdio.h>

int main()
{
    unsigned int a = 1 + (1<<8) + (1<<17) + (1<<24);
    unsigned short *b = *((unsigned short *)(&a) + 1);
    printf("%u\n", b);

    return 0;
}
