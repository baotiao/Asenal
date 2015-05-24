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

int cnt[N];
int a[N];
map<int, int> mp;
map<int, int>::iterator iter;
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    int n;
    int ans;
    while (scanf("%d", &n) != EOF) {
        mp.clear();
        ans = 0;
        int tmp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (tmp == 0) {
                continue;
            }
            if (ans == -1) {
                continue;
            }
            iter = mp.find(tmp);
            if (iter == mp.end()) {
                mp[tmp] = 1;
            } else {
                mp[tmp]++;
                if (mp[tmp] == 2) {
                    ans++;
                } else if (mp[tmp] > 2) {
                    ans = -1;
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

