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
#define N 2010
#define M 1000010
#define PRIME 999983
int hp[M];
int hplen;
int n, m, k;
int mp[N][N];
int flag[N];
lld ans;
int fa[N];
int len[N];

bool cmp(int a, int b)
{
    return a < b;
}

void prim(int num)
{
    int bj = num;
    flag[num] = num;
    for (int i = 0; i < n; i++) {
        if (mp[num][i] == 0) {
            len[i] = MAX;
        } else {
            len[i] = mp[num][i];
        }
    }
    len[num] = 0;
    for (int i = 0; i < n; i++) {
        int minp = MAX;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if(flag[j] == -1 && minp > len[j]) {
                minp = len[j];
                u = j;
            }
        }
        if (u == -1) {
            break;
        }
        flag[u] = num;
        for (int kk = 0; kk < n; kk++) {
            if (flag[kk] == -1 && mp[u][kk] != 0 && len[kk] > mp[u][kk]) {
                len[kk] = mp[u][kk];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (flag[i] == num) {
            hp[hplen++] = len[i];
            push_heap(hp, hp + hplen, cmp);
            ans += (lld)len[i];
        }
    }
}
    
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while (T--) {
        hplen = 0;
        ans = 0;
        scanf("%d%d%d", &n, &m, &k);
        clr(mp, 0);
        clr(flag, -1);
        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a--;
            b--;
            mp[a][b] = mp[b][a] = c;
        }
        int cnt = 0;
        int im = 0;
        debug(k);
        for (int i = 0; i < n; i++) {
            if (flag[i] == -1 && cnt >= k) {
                im = 1;
                break;
            }
            if (flag[i] == -1) {
                debug(i);
                cnt++;
                prim(i);
            }
        }
        if (im == 1) {
            printf("Impossible!\n");
        } else {
            
            k -= cnt;
            while (k > 0 && hplen >= 0) {
                debug(hp[0]);
                ans -= hp[0];
                pop_heap(hp, hp + hplen, cmp);
                hplen--;
                k--;
            }

            printf("%lld\n", ans);
        }
    }
    return 0;
}
