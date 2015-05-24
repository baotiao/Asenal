#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<map>
#include<ctime>
#include<set>
typedef long long lld; 
using namespace std; 
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

void fun(char* strname)
{
    int len = strlen(strname);
    char tmp[40];
    int i;
    for (i = 0; i < len; i++) {
        if (strname[i] == '_') {
            break;
        }
        tmp[i] = strname[i];
    }
    tmp[i] = '\0';
    printf("%s\n", tmp);
}
int main()
{
    char str[40] = "heihei_1";
    fun(str);

    return 0;
}
