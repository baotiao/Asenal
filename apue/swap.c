#include<stdio.h>
void swap(void *p1, void *p2, int size)
{
    char tmp[20];
    memcpy(tmp, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, tmp, size);
}

//void *lsearch(void *
int main()
{
    double a = 5.01, b = 10.11;
    char *s1 = "abcde\0";
    char *s2 = "bdeft\0";

    printf("%s %s\n", s1, s2);
    swap(&s1, &s2, 1);
    printf("%s %s\n", s1, s2);
    return 0;
}
