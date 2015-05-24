#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 52

int main()
{

    srand(time(NULL));
    int tmp;
    int flag[N];
    int ans[N];
    int len = 0;
    memset(flag, 0, sizeof(flag));

    for (int i = 0; i < N; i++) {
        tmp = rand() % N + 1;
        while (flag[tmp] == 1) {
            tmp = rand() % N + 1;
        }
        ans[len++] = tmp;
        flag[tmp] = 1;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
