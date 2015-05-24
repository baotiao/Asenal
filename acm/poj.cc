#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <queue> 
#include <map>
#include <ctime>
#include <set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define T 20500
#define N 105

#define PRIME 999983

struct node{
    int v, c;
}q[N];

bool cmp(node a, node b) {
    return a.v > b.v;
}
int mn[N][40];
int op[N][40];
int cn[N];
int dp[T];
int dp1[T];

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i].v);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i].c);
    }

    sort(q, q + n, cmp);
    for (int i = 0; i < T; i++) {
        dp[i] = MAX;
        dp1[i] = MAX;
    }
    debug(dp[0]);
    dp[0] = 0;
    clr(cn, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        int j;
        q[i].c = 100000;
        for (j = 0; (1 << (j + 1)) < q[i].c + 1; j++) {
            op[i][cnt] = (1 << j);
            debug(op[i][cnt]);
            mn[i][cnt++] = (1 << j) * q[i].v;
        }
        op[i][cnt] = (q[i].c - (1 << j) + 1);
            debug(op[i][cnt]);
        mn[i][cnt++] = (q[i].c - (1 << j) + 1) * q[i].v;
        cn[i] = cnt;
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < cn[j]; k++) {
            for (int i = T; i >= mn[j][k]; i--) {
                if (dp[i - mn[j][k]] != MAX) {
                    dp[i] = min(dp[i], dp[i - mn[j][k]] + op[j][k]);
                }
            }
        }
    }
    dp1[0] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = q[j].v; i < T; i++) {
            if (dp1[i - q[j].v] != MAX) {
                dp1[i] = min(dp1[i - q[j].v] + 1, dp1[i]);
            }
        }
    }
    int ans = MAX;
    for (int i = t; i <= T; i++) {
        if (dp[i] != MAX && dp1[i - t] != MAX) {
            ans = min(ans, dp[i] + dp1[i - t]);
        }
    }
    debug(dp[t]);
    if (ans == MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

            
    return 0;
}

