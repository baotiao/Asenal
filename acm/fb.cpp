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

int dp[N][N];

bool check_in(char c) {
    if ((c >= 'a' && c <= 'z') || c == ' ' || c == ':' || c == ')' || c =='(') {
        return true;
    } 
    return false;
}

bool check_no(char c) {
    if ((c >= 'a' && c <= 'z') || c == ' ' || c == ':') {
        return true;
    } 
    return false;
}
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    freopen("b", "w", stdout);
    #endif
    int T;
    scanf("%d", &T);
    string str;
    getchar();
    int len;
    bool flag = 0;
    int cas = 1;
    while (T--) {
        flag = 1;
        getline(cin, str);
        len = str.length();
        clr(dp, 0);
        int i;
        for (i = 0; i < len; i++) {
            if (check_in(str[i])) {
            } else {
                break;
            }
        }
        if (i != len) {
            flag = 0;
            printf("Case #%d: NO\n", cas++);
        } else {
            clr(dp, 0);
            for (i = 0; i < len; i++) {
                if (check_no(str[i])) {
                    dp[i][i] = 1;
                }
            }
            for (i = 1; i < len; i++) {
                for (int j = 0; j + i < len; j++) {
                    int k = j + i;
                    if (str[j] == '(' && str[k] == ')' && (dp[j + 1][k - 1] == 1 || i == 1)) {
                        dp[j][k] = 1;
                    } else if (check_no(str[j]) && check_no(str[k]) && (dp[j + 1][k - 1] == 1 || i == 1)) {
                        dp[j][k] = 1;
                    } else if (i == 1 && str[j] == ':') {
                        dp[j][k] = 1;
                    }
                    for (int p = j; p < k; p++) {
                        if (dp[j][p] == 1 && dp[p + 1][k] == 1) {
                            dp[j][k] = 1;
                        }
                    }
                }
            }
            //for (int i = 0; i < len; i++) {
            //    for (int j = 0; j < len; j++) {
            //        printf("%d ", dp[i][j]);
            //    }
            //    printf("\n");
            //}
            if (dp[0][len - 1] == 0) {
                printf("Case #%d: NO\n", cas++);
            } else {
                printf("Case #%d: YES\n", cas++);
            }
        }
    }
    return 0;
}
