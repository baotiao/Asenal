#include <iostream>
#include <string>
#include <string.h>
#include "slice.h"
using namespace std;
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;

int main()
{
    const char *p = "chenzongzhi";
    int len = strlen(p);
    ld::Slice s(p, len);

    string str = s.ToString();
    printf("%s\n", str.c_str());

    string name("chenzongzhi");

    ld::Slice s1(name);
    printf("s1 size %zu\n", s1.size());

    printf("s1 data %s\n", s1.data());


    ld::Slice s2("xuyangyang");
    printf("s2 size %zu\n", s2.size());

    printf("s2 data %s\n", s2.data());

    ld::Slice s3("chen");

    debug(s1.starts_with(s3));

    ld::Slice s4 = s3;

    ld::Slice s5(s3);


    return 0;
}
