#include<iostream>
#include<stdio.h>
#include "Student.h"
#include<string>
#include "TjuStudent.h"
using namespace std;

int main()
{
    string s1 = "chenzongzhi";
    string s2 = "heihei";
    //Student *s = new Student("chenzongzhi", "heihei");
    //s->getName();

    Student *tju = new TjuStudent("chenzongzhi", "fujian ", "pengxianggongyu", 3007218002);
    tju->getName();

    TjuStudent tju1("guanhongyu", "pangjin", "pangxiangongyu", 3007218004);
    tju1.getName();
    return 0;
}
