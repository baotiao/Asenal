#include<stdio.h>
#include<string.h>
char *itoa(int num, char *s)
{
    int a[100];
    int i = 0;
    char *p = s;
    while(num) {
        a[i] = num % 10;
        num /= 10;
        i++;
    }
    for (;i>0;i--) {
        *p = a[i-1] + '0';
        p++;
    }
    *p = '\0';
    char *q = s;
    return q;
}

int main()
{
    char *s1 = "hello";
    printf("%s\n", s1);
    char s[100];
    printf("%s\n",itoa(123,s));
    return 0;
}
