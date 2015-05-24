#include<stdio.h>
#include<string.h>


int main()
{
    char* friends = {"Ai", "Bob"};
    char* copy = strdup(friends[0]);
    printf("%s\n", &copy);
    return 0;
}
