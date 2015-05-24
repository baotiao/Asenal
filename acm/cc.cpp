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
#define N 110
#define PRIME 999983

int a[N];

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    int T;
    scanf("%d", &T);
    int n, k;
    int num;
    while (T--) {
        scanf("%d %d", &n, &k);
        debug(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        num = min(k, n - k);
        int b = 0, s = 0;
        debug(b);
        for (int i = 0; i < num; i++) {
            s += a[i];
        }
        for (int i = num; i < n; i++) {
            b += a[i];
        }
        printf("%d\n", b - s);
    }
    return 0;
}

