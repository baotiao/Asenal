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
#define N 1000010
#define PRIME 999983
char s[N];
int next[N];
int len;
void getnext()
{
    int k=-1,j=0;
    next[0]=-1;
    while(j<len)
    {
        if(k==-1||s[k]==s[j])
        {
            k++;
            j++;
            next[j]=k;
        }
        else
        k=next[k];
    }
}
int main()
{
    #ifdef ADD_FREOPEN
    freopen("a", "r", stdin);
    #endif
    int T;
    while (gets(s)) {
        len = strlen(s);
        if (len == 1 && s[0] == '#') {
            break;
        }
        getnext();
        for (int i = 0; i < len; i++) {
            printf("%d ", next[i]);
        }
        printf("\n");
    }

        

    return 0;
}
