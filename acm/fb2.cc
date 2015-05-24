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
#define N 110
#define PRIME 999983
int n, m;
char mp[N][N];
int nm[N][N];
int si, sj, ei, ej;

bool IsWall(int i, int j)
{
    if (mp[i][j] == '#' || mp[i][j] == '<' || mp[i][j] == '^' || mp[i][j] == '>'
            || mp[i][j] == 'v') {
        return true;
    }
    return false;
}

void Flip(int i, int j, int t, int d)
{
    if (d == 0) {
        for (int k = j - 1; k >= 0; k--) {
            if (IsWall(i, k)) {
                break;
            }
            nm[i][k] |= (1 << t);
        }
    } else if (d == 1) {
        for (int k = i - 1; k >=0; k--) {
            if (IsWall(k, j)) {
                break;
            }
            nm[k][j] |= (1 << t);
        }
    } else if (d == 2) {
        for (int k = j + 1; k <= n; k++) {
            if (IsWall(i, k)) {
                break;
            }
            nm[i][k] |= (1 << t);
        }
    } else {
        for (int k = i + 1; k <= m; k++) {
            if (IsWall(k, j)) {
                break;
            }
            nm[k][j] |= (1 << t);
        }
    }
}
int flag[N][N][4];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool CheckIn(int i, int j)
{
    if (i >= 0 && i < m && j >= 0 && j < n) {
        return true;
    }
    return false;
}

struct node
{
    int i, j, s;
    node(int i_, int j_, int s_) :
        i(i_),
        j(j_),
        s(s_)
    {};
    node() {};
};

int Bfs()
{
    clr(flag, 0);
    queue<node> q;
    flag[si][sj][0] = 0;
    q.push(node(si, sj, 0));
    // debug(si);
    // debug(sj);
    node tmp;
    int ti, tj, ts;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        // debug(tmp.i);
        // debug(tmp.j);
        // debug(tmp.s);
        for (int i = 0; i < 4; i++) {
            ti = tmp.i + dir[i][0];
            tj = tmp.j + dir[i][1];
            if (!CheckIn(ti, tj)) {
                continue;
            }
            if (IsWall(ti, tj)) {
                continue;
            }
            ts = (tmp.s + 1) % 4;
            if (flag[ti][tj][ts] == 1) {
                continue;
            }
            if ((nm[ti][tj] & (1 << ts)) == 0) {
                q.push(node(ti, tj, tmp.s + 1));
                flag[ti][tj][ts] = 1;
                if (ti == ei && tj == ej) {
                    return tmp.s + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    int cas = 1;
    while (T--) {
        scanf("%d%d", &m, &n);
        getchar();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%c", &mp[i][j]);
            }
            getchar();
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%c", mp[i][j]);
        //     }
        //     printf("\n");
        // }
        // here;
        printf("Case #%d: ", cas++);
        clr(nm, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mp[i][j] == '<') {
                    Flip(i, j, 0, 0);
                    Flip(i, j, 1, 1);
                    Flip(i, j, 2, 2);
                    Flip(i, j, 3, 3);
                } else if (mp[i][j] == '^') {
                    Flip(i, j, 0, 1);
                    Flip(i, j, 1, 2);
                    Flip(i, j, 2, 3);
                    Flip(i, j, 3, 0);
                } else if (mp[i][j] == '>') {
                    Flip(i, j, 0, 2);
                    Flip(i, j, 1, 3);
                    Flip(i, j, 2, 0);
                    Flip(i, j, 3, 1);
                } else if (mp[i][j] == 'v') {
                    Flip(i, j, 0, 3);
                    Flip(i, j, 1, 0);
                    Flip(i, j, 2, 1);
                    Flip(i, j, 3, 2);
                } else if (mp[i][j] == 'S') {
                    si = i;
                    sj = j;
                    // debug(i);
                    // debug(j);
                } else if (mp[i][j] == 'G') {
                    ei = i;
                    ej = j;
                }
                        
            }
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%d ", nm[i][j]);
        //     }
        //     printf("\n");
        // }
        int res = Bfs();

        if (res > 0) {
            printf("%d\n", res);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}

