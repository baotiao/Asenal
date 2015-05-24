#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

class czzString {
    public:
        czzString();
        czzString(const char*);
        czzString(const czzString &);
        ~czzString();
        czzString operator + (czzString);
        int length();
        int capacity();
        char* getStr();
    private:
        char *str;
        int size;
        int end;
};

czzString::czzString()
{
    this->str = (char *)malloc(20 * sizeof(char));
    this->size = 20;
    this->end = 0;
}

czzString czzString::operator + (czzString cstr) 
{
    czzString cs;
    cs.str = strcat(str, cstr.str);
    return cs;
}
    

czzString::czzString(const char *str1)
{
    this->str = new char[20];
    const char *p = str1;
    int cnt = 0;
    for(; *p != '\0'; p++) {
        str[cnt] = *p;
        cnt++;
    }
    str[cnt] = '\0';
    end = cnt;
    size = 20;
}

czzString::czzString(const czzString &cstr)
{
    this->end = cstr.end;
    this->size = cstr.size;
    this->str = cstr.str;
}

czzString::~czzString()
{
    //free(str);
}

int czzString::length()
{
    return end;
}

int czzString::capacity()
{
    return size - end;
}
char* czzString::getStr()
{
    return str;
}
    
int main()
{
    czzString str("chenzongzhi");
    printf("%s\n", str.getStr());
    czzString s1("xuyangyang");
    czzString s2 = str + s1;
    printf("%s\n", s2.getStr());
    char *str45 = "heihei";
    const char* b = str45;
    
    printf("%s\n", b);

    return 0;
}

