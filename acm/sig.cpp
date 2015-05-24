#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

class Sing {
    public:
        Sing() {};
        ~Sing() {};
        static Sing *getInstance();
        static void close();
        static int num;
    private:
        static Sing *s;
};

Sing *Sing::s = NULL;
int Sing::num = 10;

Sing *Sing::getInstance()
{
    if (s == NULL) {
        s = new Sing();
        //num = 10;
        num++;
        assert(s != NULL);
    }

    return s;
}

void Sing::close()
{
    if (s != NULL) {
        delete s;
    }
}

int main()
{
    Sing *s1 = Sing::getInstance();
    printf("%d\n", s1->num);
    s1 = Sing::getInstance();
    printf("%d\n", s1->num);


    return 0;
}
