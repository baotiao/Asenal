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
#define N 16000010
#define PRIME 999983
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if (l1 + l2 != l3) {
            return false;
        }
        int dp[l3 + 10][l3 + 10];
        clr(dp, 0);
        dp[0][0] = 1;
        for (int i = 1; i <= l2; i++) {
            if (dp[0][i - 1] == 1 && s2[i - 1] == s3[i - 1]) {
                dp[0][i] = 1;
            }
        }
        for (int i = 1; i <= l1; i++) {
            if (dp[i - 1][0] == 1 && s1[i - 1] == s3[i - 1]) {
                dp[i][0] = 1;
            }
        }

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (dp[i][j - 1] == 1 && s2[j - 1] == s3[i - 1 + j - 1 + 1]) {
                    dp[i][j] = 1;
                } else if (dp[i - 1][j] == 1 && s1[i - 1] == s3[i - 1 + j - 1 + 1]) {
                    dp[i][j] = 1;
                }
            }
        }
        if (dp[l1][l2] == 1) {
            return true;
        } else {
            return false;
        }
                

    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%d %d\n", rand(), rand());

    return 0;
}

