#include<stdio.h>
#include<iostream>
#include<string>
#include "Student.h"
using namespace std;

Student::Student()
{
    //printf("Hello World\n");
}

Student::Student(string init_name, string init_address) 
{
    printf("Hello World1\n");
    //strcpy(init_name, this->name);
    //strcpy(init_address, this->address);
    name = init_name;
    address = init_address;
}

Student::~Student()
{

}

string Student::getName()
{
    return this->name;
}

string Student::getAddress()
{
    return this->address;
}

