#include<stdio.h>
struct node {
    char c;
    struct node *next;
};
typedef struct node Node;

Node *init(char *s)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *p = head;
    Node *t;
    char *sp = s;
    int i=0;
    while (*sp != '\0') {
        t = (Node *)malloc(sizeof(Node));
        t->c = s[i];
        p->next = t;
        p = t;
        i++;
        sp++;
    }
    return head->next;
}
        

void print(Node *head)
{
    while(head != NULL) {
        printf("%c", head->c);
        head = head->next;
    }
}

int main()
{
    char *str = "iamchenzongzhi\0";
    Node *head = init(str);
    print(head);
    return 0;
}


