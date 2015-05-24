#include <iostream>

//template <typename T>
class myVector {

    public:
        myVector() : cnt(0) {}
        void push_back(int new_num);

    private:
        int num[100];
        int cnt;

};

void myVector::push_back(int new_num)
{
    
}

int main()
{
    myVector v;
    

    return 0;
}
