#include<stdio.h>
char *fun(int num)
{
    char s[100];
    int i = 0;
    while (num) {
        s[i] = num%10 + '0';
        num /= 10;
        i++;
    }
    s[i] = '\0';
}

int main()
{
    printf("%s\n",*fun(123));
    return 0;
}
