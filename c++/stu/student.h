#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;


class Student {
    string address;

    public:
        string name;
        Student();
        Student(string init_name, string init_address);
        ~Student();
        virtual string getName();
        string getAddress();
};

#endif
