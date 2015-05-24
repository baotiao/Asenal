#include <iostream>
using namespace std;

class CBase
{
public:
    CBase();
    CBase(int x);

    virtual int func() const    //虚函数
    {
        cout<<"CBase function! ";
        return 100;
    }
private:
    int x_;
};


class CDerive : public CBase
{

public:
    int func() const        //在派生类中重新定义虚函数
    {
        cout<<"CDerive function! ";
        return 200;
    }
};

int main()
{
    CDerive obj1;
    CBase* p1=&obj1;
    CBase& p2=obj1;
    CBase obj2;

    obj1.func();    //静态绑定：调用对象本身（派生类CDerive对象）的 func 函数
    p1->func();    //动态绑定：调用被引用对象所属类（派生类CDerive）的 func 函数
    p2.func();    //动态绑定：调用被引用对象所属类（派生类CDerive）的 func 函数
    obj2.func();    //静态绑定：调用对象本身（基类CBase对象）的函数
}
