#include <iostream>
#include <stdio.h>
using namespace std;

class CBase
{
public:
    CBase() { printf("No paramater\n");}
    CBase(int x) { printf("Hello World %d\n", x);}

private:
    int x_;
};

class CDriver : public CBase
{
public:
    CDriver() { printf("It's CDriver no paramater construct\n");}
    CDriver(int x):CBase(x) { printf("It's CDriver Hello World %d\n", x);}

};

int main()
{
    CBase cb(5);
    CDriver cd;
    CDriver cd1(6);

    return 0;
}
