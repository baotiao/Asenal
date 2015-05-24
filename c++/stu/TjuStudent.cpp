#include<string>
#include<iostream>
using namespace std;
#include "TjuStudent.h"
#include "Student.h"

TjuStudent::TjuStudent()
{
    cout<<"I am a TJU student\n"<<endl;
}

TjuStudent::TjuStudent(string name, string address, string live, int num) : Student(name, address)
{
    this->num = num;
    this->live = live;
}

string TjuStudent::getName()
{
    cout<<"This is Children\n"<<endl;
    //return this->live;
    return this->live + this->name;
}
