#include<stdio.h>
class A {
public:
    void fun() {
        printf("a\n");
    }
};
class B:public A {
public:
    void fun() {
        printf("b\n");
    }
};
int main()
{
    A a;
    B b;
    a.fun();
    b.fun();
    return 0;
}
