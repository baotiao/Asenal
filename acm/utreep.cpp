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
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    int n;
    int ans;
    while (T--) {
        scanf("%d", &n);
        ans = 1;
        int t = 1;
        while (t <= n) {
            if (t % 2 == 1) {
                ans *= 2;
            } else {
                ans++;
            }
            t++;
        }
        printf("%d\n", ans);

    }
    return 0;
}

