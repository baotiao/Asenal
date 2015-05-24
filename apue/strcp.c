#include<stdio.h>
#include<string.h>
int main()
{
    char *s = "i am chenzongzhi";
    char* s1 = malloc(100 * sizeof(char));
    strncpy(s1, s, 10);
    printf("%s\n", s1);
    return 0;
}
