#ifndef T_H
#define T_H
#include <iostream>
using namespace std;
class A
{
    public:
    struct node {
        int hei;
        node *b;
    };

    typedef node* Tnode;
    Tnode fun(Tnode p) {
        struct node a;
        printf("Hello world\n");
    }

    int heihei();

};


#endif
