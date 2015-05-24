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
#define N 1600
#define PRIME 999983

class Solution {
    public:
        int dp[N][N];
        int len1, len2;
        int minDistance(string word1, string word2) {
            len1 = word1.length();
            len2 = word2.length();
            clr(dp, -1);
            dp[0][0] = 0;
            for (int i = 0; i < len1; i++) {
                for (int j = 0; j < len2; j++) {
                    if (word1[i] == word2[j]) {
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1] + 1);
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + 1);
                    }
                }
            }
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

        }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    return 0;
}

