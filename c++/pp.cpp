#include <iostream>
using namespace std;

int *getNum()
{
    int a = 10;
    return &a;
}

int main()
{
    int **p;
    p = (int **) malloc (sizeof(*p) * 10);
    for (int i = 0; i < 10; i++) {
        p[i] = (int *)malloc(sizeof(int) * 10);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            p[i][j] = getNum();
        }
    }

    printf("p[i][j] %d\n", p[5][5]);

    for (int i = 0; i < 10; i++) {
        free(p[i]);
        p[i] = NULL;
    }
    free(p);

    p = NULL;
    int *a = new int();
    *a = 10;
    printf("%d\n", *a);
    return 0;
}
