#include<stdio.h>
struct node {
    int num;
    struct node *next;
};
typedef struct node Node;

Node *merge(Node *a, Node *b)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *p = head;
    Node *t;
    while (a != NULL && b != NULL) {
        if (a->num <= b->num) {
            if (head == p) {
                t = (Node *)malloc(sizeof(Node));
                t->num = a->num;
                p->next = t;
                p = t;
                a = a->next;
                continue;
            }
            if (p->num == a->num) {
                a = a->next;
                continue;
            }
            t = (Node *)malloc(sizeof(Node));
            t->num = a->num;
            p->next = t;
            p = t;
            a = a->next;
        } else {
            if (head == p) {
                t = (Node *)malloc(sizeof(Node));
                t->num = b->num;
                p->next = t;
                p = t;
                b = b->next;
                continue;
            }
            if (p->num == b->num) {
                b = b->next;
                continue;
            }
            t = (Node *)malloc(sizeof(Node));
            t->num = b->num;
            p->next = t;
            p = t;
            b = b->next;
        }
    }
    while (a != NULL) {
        if (a->num == p->num) {
            a = a->next;
            continue;
        }
        t = (Node *)malloc(sizeof(Node));
        t->num = a->num;
        p->next = t;
        p = t;
        a = a->next;
    }
    while (b != NULL) {
        if (b->num == p->num) {
            b = b->next;
            continue;
        }
        t = (Node *)malloc(sizeof(Node));
        t->num = b->num;
        p->next = t;
        p = t;
        b = b->next;
    }
    return head->next;
}


void print(Node *t)
{
    while(t != NULL) {
        printf("%d\n", t->num);
        t = t->next;
    }
}

int main()
{
    Node *a = (Node *)malloc(sizeof(Node));
    Node *st = a;

    Node *b = (Node *)malloc(sizeof(Node));
    Node *stb = b;

    Node *t = (Node *)malloc(sizeof(Node));
    t->num = 0;
    a->next = t;
    a = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 11;
    a->next = t;
    a = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 12;
    a->next = t;
    a = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 13;
    a->next = t;
    a = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 14;
    a->next = t;
    a = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 7;
    b->next = t;
    b = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 12;
    b->next = t;
    b = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 14;
    b->next = t;
    b = t;

    t = (Node *)malloc(sizeof(Node));
    t->num = 15;
    b->next = t;
    b = t;
    print(st->next);
    print(stb->next);
    print(merge(st->next, stb->next));
    return 0;
}
