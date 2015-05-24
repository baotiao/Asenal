#include<stdio.h>
#include<string.h>
int cmp(char *s1, char *s2)
{
    char *p = s1;
    char *q = s2;
    while (*p != '\0' && *q !='\0') {
        if (*p == *q) {
            p++,q++;
        }
        return *p - *q;
    }
    return 0;
}

int main()
{
    char s1[10]="caz";
    char s2[10]="chenzong";
    printf("%d\n",cmp(s1,s2));
    return 0;
}
