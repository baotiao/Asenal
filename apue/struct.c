#include<stdio.h>
#define N 1000
struct node {
    char *str;
    struct node *next;
}q[N];
int cnt;
typedef struct node Node;

void init(char *str[])
{
    int i=0;
    Node tmp;
    Node *p = q;
    p->str = str[0];
    Node *t;
    p++;
    for (i=1; i<cnt; i++) {
        p->str = str[i];
        (p-1)->next = p;
        p++;
    }
    (p-1)->next = NULL;
    t = q;
    while(1) {
        printf("%s ", t->str);
        t = t->next;
        if (t == NULL) {
            break;
        }
    }
}

Node *init1(char *str[])
{
    int i = 0;
    Node tmp;
    Node *p = malloc(sizeof(Node));
    p->str = str[0];
    Node *q = (Node *)malloc(sizeof(Node));
    Node *st = p;
    p->next = q;
    p = q;
    for (i=1; i<cnt; i++) {
        q = malloc(sizeof(Node));
        q->str = str[i];
        p->next = q;
        p = q;
    }
    p->next = '\0';
    p = st;
    return st;
}

int main()
{
    char *str[50] = {"now", "is", "the", "time", "for", "all", "good", "men", "to", "come"};
    cnt = 0;
    int i = 0;
    for(i=0; i<50; i++) {
        if (str[i] == NULL) {
            break;
        }
        cnt++;
        //printf("%s\n", str[i]);
    }
    //printf("%d\n", cnt);
    Node *p = init1(str);
    while (1) {
        printf("%s ", p->str);
        p = p->next;
        if (p == NULL) {
            break;
        }
    }

    return 0;
}
