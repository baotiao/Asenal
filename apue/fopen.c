#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;

int main()
{
    FILE *fp = fopen("./binary2", "wb");

    if (fp == NULL) {
        fprintf(stdout, "fp is null\n");
        return 0;
    }
    char x[5] = "ABCD";
    fwrite(x, sizeof(char), sizeof(x) / sizeof(char), fp);


    FILE *fp1 = fopen("./binary1", "r+");
    if (fp1 == NULL) {
        fprintf(stdout, "fp1 is null\n");
        return 0;
    }
    char name[10];
    debug(strlen(name));
    debug(sizeof(name));
    fread(name, sizeof(name), 20, fp1);

    debug(name);

    ////char *name = "chenzongzhi";
    //int writeNum;
    ////fwrite(name, sizeof(char), writeNum, fp);
    ////printf("writeNum is %d\n", writeNum);
    ////fclose(fp);

    //char name[20];

    //debug(strlen(name));
    //fread(name, sizeof(name), strlen(name), fp);
    //printf("name is %s\n", name);
    //printf("readNum is %d\n", writeNum);

    //fwrite(name, sizeof(char), 20, fp);
    //fclose(fp);
    return 0;
}
