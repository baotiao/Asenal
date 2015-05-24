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
#define N 1010
#define PRIME 999983
int a[N];
int cnt[N];

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    int n;
    int tmp;
    while (scanf("%d", &n) != EOF) {
        clr(a, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            a[tmp]++;
        }
        bool ans = 0;
        for (int i = 0; i < N; i++) {
        //    debug(a[7]);
            if (a[i] > (n + 1) / 2) {
                
                ans = 1;
                break;
            }
        }
        if (ans == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}

