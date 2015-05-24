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
    int n, m, x, y;

    int T;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            if (x == 1) {
                a[x + 1] += a[x] - y;
            } else if (x == n) {
                a[x - 1] += y - 1;
            } else {
                a[x - 1] += y - 1;
                a[x + 1] += a[x] - y;
            }
            a[x] = 0;
        }
        for (int i = 1; i <= n; i++) {
            printf("%d\n", a[i]);
        }
    }

    return 0;
}

