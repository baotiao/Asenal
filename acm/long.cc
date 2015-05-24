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

class Solution
{
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
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        int dp[len][len];
        clr(dp, 0);

        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }

        int i, j;

        int ans = 1;
        int p = 0;
        for (int k = 1; k < len; k++) {
            for (i = 0; i < len; i++) {
                j = i + k; 
                if (j >= len) {
                    break;
                }
                if ((s[i] == s[j]) && (k == 1 || dp[i + 1][j - 1] != 0)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (ans < dp[i][j]) {
                        ans = dp[i][j];
                        p = i;
                    }
                }
            }
        }

        string str = s.substr(p, ans);
        return str;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    debug(s.longestPalindrome("a"));

    return 0;
}

