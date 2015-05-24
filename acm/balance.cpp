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
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 1010
#define PRIME 999983

int mp[N][N][2];
int num[N][2];
int n;
int cnt[N];
int w[N];
int l[N], r[N];
int la[N], ra[N];

int dfs(int now)
{
    for (int i = 0; i < n; i++) {
        if (mp[now][i][0] != -1) {
            l[now] += dfs(i);
        }
        if (mp[now][i][1] != -1) {
            r[now] += dfs(i);
        }
    }
    
    if (l[now] > r[now]) {
        ra[now] = l[now] - r[now];
    } else {
        la[now] = r[now] - l[now];
    }
    w[now] = l[now] + r[now] + ra[now] + la[now] + 10;

    return w[now];
}

int main()
{
    #ifdef ADD_FREOPEN
    freopen("a", "r", stdin);
    #endif
    scanf("%d", &n);
    clr(mp, -1);
    clr(cnt, 0);
    clr(num, 0);
    clr(w, 0);
    clr(l, 0);
    clr(r, 0);
    clr(la, 0);
    clr(ra, 0);
    int tmp;
    string str;
    char c;
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
        tmp = 0;
        c = getchar();
        if (c != '\n') {
            while (1) {
                c = getchar();
                if (c == '\n') {
                    mp[i][tmp][0] = 1;
                    cnt[tmp]++;
                    tmp = 0;
                    break;
                }
                if (c == ' ') {
                    mp[i][tmp][0] = 1;
                    cnt[tmp]++;
                    tmp = 0;
                } else {
                    tmp = tmp * 10 + (c - '0');
                }
            }
        }
        scanf("%d", &r[i]);
        tmp = 0;
        c = getchar();
        if (c != '\n') {
            while (1) {
                c = getchar();
                if (c == '\n') {
                    mp[i][tmp][1] = 1;
                    cnt[tmp]++;
                    tmp = 0;
                    break;
                }
                if (c == ' ') {
                    cnt[tmp]++;
                    mp[i][tmp][1] = 1;
                    tmp = 0;
                } else {
                    tmp = tmp * 10 + (c - '0');
                }
            }
        }
    }

    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        if (mp[i][j][0] != -1) {
    //            printf("i %d j %d 0\n", i, j);
    //        }
    //        if (mp[i][j][1] != -1) {
    //            printf("i %d j %d 1\n", i, j);
    //        }
    //    }
    //}

    //dfs(0);
    //dfs(20);
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d: %d %d\n", i, la[i], ra[i]);
    }
        


    return 0;
}
