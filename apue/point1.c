#include<stdio.h>
struct node {
    int num;
    int *p;
};
int main()
{
    struct node n1,n2;
    n1.p = &n2;
    n1.num = 1;
    n2.num = 2;
    struct node *q = &n1;
    for(; q != NULL; q++) {
        printf("%d\n", *q->num);
    }
    return 0;
}
