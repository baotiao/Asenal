#include <stdio.h>

int main()
{
    int a[20];
    int out[20];
    int len = 0;
    for (int i = 0; i < 20; i++) {
        a[i] = 1;
    }
    int cnt = 3;
    int now = 0;
    while (len < 20) {
        printf("%d %d\n", now, cnt);
        if (a[now] == 1) {
            cnt--;
            if (cnt == 0) {
                a[now] = 0;
                out[len] = now;
                len++;
                cnt = 3;
            }
            now = (now + 1) % 20;
        } else {
            now = (now + 1) % 20;
        }
    }
    for (int i = 0; i < 20; i++) {
        printf("%d ", out[i] + 1);
    }
    printf("\n");
    return 0;
}

        
