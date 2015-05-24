#include <iostream> 
#include <stdio.h>
#include <memory>
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
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<"_______________here \n"<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 10 
#define N 16000010
#define PRIME 999983

int a[MAX] = {4, 3, 5, 5, 3, 6, 1, 1, 8, 20};
int fa[MAX];


int mp[10][10];
int flag[10];
int flag1[MAX];
int flag2[MAX];
int ans_flag[MAX];
int cal[MAX];

int ans;
int ans_tot;


void init()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if(mp[i][j] == 1) {
                mp[j][i] = 1;
            }
        }
    }
}

bool check(int now)
{
    for (int i = 0; i < MAX; i++) {
        if (mp[now][i] == 1 && flag[i] == 1) {
            return false;
        }
    }
    return true;
}

void try_flag(int now, int len) {
    printf("%d %d\n", now, len);
    if (now == len) {
        for (int i = 0; i < MAX; i++) {
            flag2[i] = flag1[i];
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (flag2[cal[i]] == 1 && flag2[cal[j]] == 1 && mp[cal[i]][cal[j]] == 1) {
                    return;
                }
            }
        }
        here;
        int tot = 0;
        for (int i = 0; i < len; i++) {
            if (flag2[cal[i]] == 1) {
                for (int j = 0; j < MAX; j++) {
                    if (mp[cal[i]][j] == 1 && flag2[j] == 1) {
                        flag2[j] = 2;
                        //return ;
                    }
                }
            }
        }

        for (int i = 0; i < MAX; i++) {
            if (flag2[i] == 1) {
                tot += a[i];
            }
        }
        debug(tot);
        if (tot > ans_tot) {
            for (int i = 0; i < MAX; i++) {
                ans_flag[i] = flag2[i];
            }
            debug("ans_flag");
            for (int i = 0; i < MAX; i++) {
                printf("%d ", ans_flag[i]);
            }
            printf("\n");
            ans_tot = tot;
            ans = max(ans, ans_tot);
        }
        return ;
    }

    flag1[cal[now]] = 0;
    try_flag(now + 1, len);
    flag1[cal[now]] = 1;
    try_flag(now + 1, len);
}
    
void change_type()
{
    for (int i = 0; i < MAX; i++) {
        if (flag[i] == 1 && ans_flag[i] == 0) {
            flag[i] = 2;
        } else {
            flag[i] = ans_flag[i];
        }
    }
}

int get_sum(int now, int dep)
{
    int len = 0;
    ans_tot = 0;
    for (int i = 0; i < MAX; i++) {
        if (flag[i] == 1) {
            ans_tot += a[i];
        }
        flag1[i] = flag[i];
    }
    int sun = now;
    while (dep--) {
        cal[len++] = sun;
        if (fa[sun] == -1) {
            break;
        }
        sun = fa[sun];
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", cal[i]);
    }
    
    try_flag(0, len);
    change_type();
    for (int i = 0; i < MAX; i++) {
        printf("%d ", flag[i]);
    }
    return ans_tot;
}



void dfs(int now, int sum)
{
    if (flag[now] == 2) {
        return;
    }
    for (int i = 0; i < MAX; i++) {
        if (mp[now][i] == 1 && flag[i] == 0) {
            //int tmp1 = sum;
            debug(i);
            fa[i] = now;
            int tmp = get_sum(i, 11);
            debug(tmp);
            dfs(i, sum);
        }
    }
}


int main()
{
    clr(mp, 0);
    clr(flag, 0);
    for (int i = 0; i < MAX; i++) {
        fa[i] = -1;
    }

    mp[0][9] = 1;
    mp[0][6] = 1;
    mp[1][9] = 1;
    mp[1][2] = 1;
    mp[4][6] = 1;
    mp[2][3] = 1;
    mp[4][7] = 1;
    mp[3][7] = 1;
    mp[8][5] = 1;
    mp[4][5] = 1;
    mp[3][5] = 1;

    init();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }

    flag[0] = 1;
    ans = -1;
    dfs(0, 4);
    
    debug(ans);
    for (int i = 0; i < MAX; i++) {
        if (flag[i] == 1) {
            printf("%d ", i);
        }
    }
    
    return 0;
}
