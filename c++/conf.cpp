#include <iostream>
#include <stdio.h>
#include <unistd.h>

#define WORD_SIZE 1024
struct qf_confitem {
    char name[WORD_SIZE];
    char value[WORD_SIZE];
};

struct qf_confdata {
    int num;
    int size;
    qf_confitem *item;
};

int read_conf(const char* path, qf_confdata *qf_confdata) 
{
    struct stat info;

    int val = stat(path, &info);

    return 0;

}

int main()
{
    printf("hello \n");
    return 0;
}
