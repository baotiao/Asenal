#include<stdio.h>
#include<string.h>
void strcpy1(char *to, char *from)
{
    int len = strlen(to);
    printf("%d\n", len);
    char *q = from;
    while (*to != '\0') {
        *q = *to;
        to++;
        q++;
    }
    *q='\0';
    printf("%s\n", to);
    return ;
}
int main()
{
    char str1[] = "hello world";
    char str2[100];
    strcpy1(str1, str2);
    printf("%s\n",str2);
    printf("%s\n",str1);
    return 0;
}
