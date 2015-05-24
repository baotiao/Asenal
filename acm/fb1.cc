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
#define N 1010
#define PRIME 999983
int p[N], c[N], f[N];
int sp, sc, sf;
int n;

bool dfs(int i, int np, int nc, int nf)
{
    if (np == sp && nc == sc && nf == sf) {
        return true;
    }
    if (i >= n) {
        return false;
    }
    if (np > sp || nc > sc || nf > sf) {
        return false;
    }
    if (dfs(i + 1, np + p[i], nc + c[i], nf + f[i])) {
        return true;
    }
    if (dfs(i + 1, np, nc, nf)) {
        return true;
    }
    return false;
}
int main()
{
    #ifdef ZDEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    int cas = 1;
    while (T--) {
        scanf("%d%d%d", &sp, &sc, &sf);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &p[i], &c[i], &f[i]);
        }
        bool ans = dfs(0, 0, 0, 0);
        printf("Case #%d: ", cas++);
        if (ans == true) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}

