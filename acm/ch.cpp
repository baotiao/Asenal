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

#define here cout<<"_______________here "<<endl;
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
    int a, b, c;
    scanf("%d", &T);
    debug(T);
    int ans1, ans2;
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        ans2 = a * b;
        ans1 = 0;
        for (int i = 0; i <= a; i++) {
            ans1 += min(b, max(c - i - 1, 0));
        }
        int div = __gcd(ans1, ans2);
        debug(div);
        printf("%d/%d\n", ans1 / div, ans2 / div);
    }
    return 0;
}
