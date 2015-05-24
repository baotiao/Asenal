#include<stdio.h>
union u_tag {
    int ival;
    float fval;
    char *sval;
} u;

int main()
{
    int a;
    float f;
    int *c;
    double d;
    char ch;
    printf("%lu\n", sizeof(u));
    printf("%lu\n", sizeof(f));
    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(c));
    printf("%lu\n", sizeof(d));
    printf("%lu\n", sizeof(ch));
    //u = 10;
    //printf("%d\n", u.ival);
    return 0;
}
