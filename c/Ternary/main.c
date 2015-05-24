#include <stdio.h>
#include <stdlib.h>
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 

typedef struct tnode *Tptr;
typedef struct tnode {
    char s;
    Tptr lokid, eqkid, hikid;
} Tnode;

Tptr t;

Tptr insert(Tptr p, char *s)
{
    if (p == NULL) {
        p = (Tptr)malloc(sizeof(Tnode));
        p->s = *s;
        printf("%c\n", p->s);
        p->lokid = p->eqkid = p->hikid = NULL;
    }
    if (*s < p->s) {
        p->lokid = insert(p->lokid, s);
    } else if (*s > p->s) {
        p->hikid = insert(p->hikid, s);
    } else {
        if (*s != '\0') {
            p->eqkid = insert(p->eqkid, ++s);
        }
    }
    return p;
}

int search(char *s)
{
    Tptr p;
    p = t;
    if (p->lokid == NULL) {
        printf("True\n");
    }
    while (p) {
        if (*s < p->s) {
            p = p->lokid;
        } else if (*s > p->s) {
            p = p->hikid;
        } else {
            if (*s == '\0') {
                return 1;
            }
            s++;
            p = p->eqkid;
        }
    }
    return 0;
}



int main()
{
    char *s[10] = {"chenzongzhi", "xuyangyang", "guanhongyu", "zhaoanan", "lichangshu", "menglingyang", "xujianguo", "qizhebing", "xiaobaisha", "xiedeng"};
    int i;
    t = NULL;
    char c;
    
    for (i = 0; i < 10; i++) {
        insert(t, s[i]);
    }
    Tptr p = t;
    printf("%d\n", p);
    printf("%c\n", t->s);
    //printf("%d\n", search("chenzongzhi"));
    return 0;
}
