#include<stdio.h>

void print(const char* str)
{
    printf("Hello %s\n", str);
}

int main()
{
    void (*myp)(const char*) = print;
    myp("guy");
    return 0;
}
