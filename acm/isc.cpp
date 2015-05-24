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
#define br printf("\n")
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 110
#define PRIME 999983
int mp[N][N];
int n, m;
int cnt[N][N];
int flag[N];
int sum[N];
int fsum[N];
int fa[N];

void dfs(int now)
{
    sum[now] = 1;
    for (int i = 0; i < n; i++) {
        if (mp[now][i] == 1 && flag[i] == 0) {
            flag[i] = 1;
            fa[i] = now;
            dfs(i);
            sum[now] += sum[i];
        }
    }
}

int main()
{
    #ifdef ADD_FREOPEN
    freopen("a", "r", stdin);
    #endif
    int T;
    scanf("%d%d", &n, &m);
    int a, b;
    clr(mp, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    clr(flag, 0);
    clr(cnt, 0);
    clr(sum, 0);
    flag[0] = 1;
    clr(fa, 0);
    dfs(0);
    fa[0] = -1;
    clr(fsum, 0);
    //sum[0] = n;
    for (int i = 1; i < n; i++) {
        fsum[i] = n - sum[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if ((mp[0][i] == 1 || mp[i][0] == 1) && sum[i] % 2 == 0) {
            ans++;
            mp[0][i] = mp[i][0] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != 0 && j != 0 && mp[i][j] == 1 && mp[j][i] == 1) {
                if (fa[i] == j) {
                    if (sum[i] % 2 == 0 && fsum[i] % 2 == 0 && fsum[i] != n - 1) {
                        ans++;
                    }
                } else if (fa[j] == i) {
                    if (sum[j] % 2 == 0 && fsum[j] % 2 == 0 && fsum[j] != n - 1) {
                        ans++;
                    }
                }
                mp[j][i] = mp[i][j] = 0;
            }
        }
    }
    printf("%d\n", ans);

//    for (int i = 0; i < n; i++) {
//        printf("%d ", fsum[i]);
//    }
//    br;
//    for (int i = 0; i < n; i++) {
//        printf("%d ", sum[i]);
//    }
//    br;
//    for (int i = 0; i < n; i++) {
//        printf("%d ", fa[i]);
//    }

    return 0;
}
