#include<stdio.h>

void fun(int *pnum, char *s[])
{
    int i = 0;
    char *p;
    int n, num;
    int j = 0;
    while (pnum[j]) {
        s[i] = (char *)malloc(sizeof(char) *1000);
        p = s[i];
        num = pnum[j];
//        printf("%d\n", num);
        while (num) {
            n = num % 10;
            *p = n + '0';
            num /= 10;
            p++;
        }
        *p = '\0';
        i++;
        j++;
    }
}

void parr(int *n) 
{
    int *p = n;
    int i;
    for(i = 0; n[i]; i++) {
        //printf("%d\n", n[i]);
    }
    i = 0;
    
    while (1) {
        printf("%d\n", *p);
        if (!(*p)) {
            break;
        }
        p++;
    }
}
int main()
{
    int a[3] = {1149, 112, 546};
    char *s[100] = {"chenzongzhi", "xuyangyang", "luzhe"};
    char *p;
    int i = 0;
    p = s[0];
//    printf("%s\n", p);
    while (p != NULL) {
        //printf("%s\n", p);
        i++;
        p = s[i];
    }
    char *str[100];
    fun(a, str);
    p = str[0];
    i = 0;
//    printf("%s\n", p);
    while (p != NULL) {
        printf("%s\n", p);
        i++;
        p = str[i];
    }
    return 0;
    //itos1(n,str);
    //printf("%s\n", str);
    //return 0;
}
