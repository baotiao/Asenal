#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
#include<stdio.h>

class Python {
    protected:
        int length;
    public:
        Python() {this->length = 10;}
        Python(int len) {this->length = len;}
        virtual ~Python() = 0;
        virtual int getArea();
        virtual int getLen();
};

int Python::getArea()
{
    return length;
}

int Python::getLen()
{
    return length;
}

Python::~Python()
{
    printf("This is the ending\n");
    
}

class Circle : public Python {
    public:
        ~Circle();
        int getArea();
        int getLen();
};

Circle::~Circle()
{
    printf("This is Circle\n");
}
int Circle::getArea()
{
    return 3 * length;
}

int Circle::getLen()
{
    return 2 * length;
}
    
class Square : public Python {
    int with;
    public:
        ~Square();
        Square(int length, int with);
        int getArea();
        int getLen();
};

Square::~Square()
{
    printf("This is the Square\n");
}

Square::Square(int length, int with) : Python(length)
{
    this->with = with;
}

int Square::getArea()
{
    return with * length;
}

int Square::getLen()
{
    return with + length;
}


int main()
{
//    Python py;
//    printf("%d\n", py.getArea());
    //Python* py1 = new Python(100);
    //printf("%d\n", py1->getArea());
    Python* py2 = new Square(11, 22);
    printf("%d\n", py2->getArea());
    printf("%d\n", py2->getLen());

    Square s(11,11);
    Square s1 = s;
    printf("%d\n", s.getArea());
    //delete py2;
    return 0;
}

