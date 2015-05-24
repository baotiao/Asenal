#include <stdio.h>
#include <iostream>

int main()
{
    char str[10][100];
    int num = 0;
    char c;
    while(scanf("%s", str[num]) != EOF) {
        c = getchar();
        num++;
        if (c == '\n')
            break;
    }
    for (int i = num - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%s\n", str[i]);
        } else {
            printf("%s ", str[i]);
        }
    }
    
    return 0;
}
