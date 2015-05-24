#include<iostream>
using namespace std;
class Base {
    public:
        virtual ~Base() {cout<<"This is Base"<<endl;}
};

class Fa : public Base {
    public:
        ~Fa() {cout<<"This is father"<<endl;}
};

int main()
{
    Base* b1 = new Fa();
    delete b1;
    return 0;
}

