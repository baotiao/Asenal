#include<iostream>
#include<stdio.h>
using namespace std;
class X {
    public:
        X(int x) { _val = x;}
        int val() { return _val;}
    private:
        int _val;
};

class Y {
    public:
        Y(int y);
        static X xval();
        static int callsXval();
    private:
        static X _xval;
        static int _callsXval;
};
int main()
{
    int num = 20;
    X *xx = new X (num);
    printf("%d\n", xx->val());
    return 0;
}
