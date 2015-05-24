#ifndef TJU_STUDENT
#define TJU_STUDENT
#include<string>
#include "Student.h"
using namespace std;

class TjuStudent : public Student {
    string live;
    int num;

    public:
        TjuStudent();
        TjuStudent(string name, string address, string live, int num);
        string getName();
};

#endif
