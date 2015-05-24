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
int numDecodings(string s) {
    int len = s.length();
    int dp[len + 10];
    int with[len + 10];
    if (len == 0 || (len >= 1 && s[0] == '0')) {
        return 0;
    }
    clr(dp, 0);
    dp[0] = 1;
    with[0] = 1;
    
    for (int i = 1; i < len; i++) {
        if (s[i] == '0' && s[i - 1] != '1' && s[i - 1] != '2') {
            return 0;
        }
    }

    for (int i = 1; i < len; i++) {
        if (s[i] != '0') {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                with[i] = dp[i - 1];
                dp[i] = with[i - 1] + dp[i - 1];
            } else {
                with[i] = dp[i - 1];
                dp[i] = dp[i - 1];
            }
        } else {
            dp[i] = with[i - 1];
        }
    }
    return dp[len - 1];
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

