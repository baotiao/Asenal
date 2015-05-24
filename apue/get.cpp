#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<map>
#include <stdint.h>
#include<ctime>
#include<set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983


int main()
{
    char line[1000];
    char key[100], value[1000];
    gets(line);
    while (scanf("%s", key) != EOF) {
        getchar();
        getchar();
        getchar();
        getchar();
        getchar();
        scanf("%s", value);
        printf("%s %s\n", key, value);
    }

    return 0;
}
