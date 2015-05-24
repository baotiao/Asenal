#include<stdio.h>
void strcat1(char *s, char *t) 
{
    char *q = s;
    char *p = t;
    while(*q != '\0') {
        q++;
    }
    while(*p != '\0') {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';
}
int main()
{
    char s[10] = "chen";
    char t[10] = "zongzhi";
    strcat1(s,t);
    printf("%s\n",s);
    return 0;
}
