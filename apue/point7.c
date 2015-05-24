#include<stdio.h>
int *cp(char *s, char *t)
{
    int a=5;
    int *p = &a;
    return p;
}
int main()
{
    char s1[10] = "hello";
    char s2[10] = "world";
    printf("%s %s\n", s1, s2);
    printf("%d\n",*cp(s1,s2));
    return 0;
}
