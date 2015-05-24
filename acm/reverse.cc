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


class Solution {
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
public:
    int reverse(int x) {
        int res = 0;
        int flag = 1;
        if (x == 0) {
            return 0;
        }
        if (x < 0) {
            x *= -1;
            flag = -1;
        }
        int mod = 1;
        while (x > 0) {
            debug(x);
            debug(res);
            mod = x % 10;
            debug(mod);
            res = res * 10 + mod;
            x /= 10;
        }
        
        return res * flag; 

    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    debug(s.reverse(-123));

    return 0;
}

