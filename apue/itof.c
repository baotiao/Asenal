#include<stdio.h>
float itof(char *s)
{
    if (s == '\0') {
        return -1;
    }
    char *p;
    p = s;
    float ans = 0.0;
    int cnt = 10;
    int flag = 0;
    int zf = 0;
    if (*p == '-') {
        zf = 1;
    }
    p++;
    for (; *p != '\0'; p++) {
        printf("%c\n", *p);
        if (*p == '.') {
            flag = 1;
            continue;
        }
        if (flag == 0) {
            ans = ans * 10 + (*p - '0');
        } else {
            printf("%f\n", (float)(*p - '0') / (float) cnt);
            ans = ans + (float)(*p - '0') / (float)cnt;
            cnt *= 10;
        }
        printf("%f\n", ans);
    }
    if (zf == 1) {
        return -ans;
    }
    return ans;
}

int main()
{
    char *s = "-123.54";
    //char *s;
    printf("%f\n", itof(s));
    return 0;
}
