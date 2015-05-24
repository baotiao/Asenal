#include<stdio.h>

struct node {
    int num;
    struct node *next;
};
typedef struct node Node;

Node * insert(int a[], int num)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *p = head;
    Node *t;
    int i = 0;
    for (i=0; i<num; i++) {
        t = (Node *)malloc(sizeof(Node));
        if (head == p) {
            t->num = -a[i];
        } else {
            t->num = a[i];
        }
        p->next = t;
        p = t;
    }
    return head->next;
}

void print(Node *p)
{
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int a[5] = {1, 3, 5, 6, 10};
    Node *p = insert(a, 5);
    print(p);
    return 0;
}
    
