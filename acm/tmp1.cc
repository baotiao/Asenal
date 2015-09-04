#include <iostream>
#include <string>

using namespace std;

struct f {
    string name;
    void (*fun)();
};

void hello()
{
    printf("hello\n");
}


class Opetator
{
    virtual void Do() = 0;
};


class GetOpt : public Operator
{
    Do();
};

map<string, Opetator *> mp;


void init()
{
    GetOpt getOpt;
    mp.insert("get", getOpt);
}

int main()
{

    mp.second()->Do();
    
    return 0;
}
