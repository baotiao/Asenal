#include<stdio.h>
char s[100];
char *inta(int num)
{
    char *p = s;
    while (num) {
        *p = num % 10;
        num /= 10;
        p++;
    }
    *p = '\0';
    printf("%s\n",p);
    return p;
}
int main()
{
    char *p = inta(123);
    printf("%s\n", p);
    return 0;
}
