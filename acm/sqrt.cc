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
#define N 16000010
#define PRIME 999983

class Solution {
typedef long long lld;
public:
    int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        lld l = 1, r = x, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (mid * mid == (lld)x) {
                return mid;
            } else if (mid * mid < (lld)x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    debug(s.sqrt(2));

    return 0;
}

