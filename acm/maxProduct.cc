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

class Solution {
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN -111111111
#define N 16000010
#define PRIME 999983
public:
    int maxProduct(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return A[0];
        }

        int res = A[0];
        int maxn = max(1, A[0]), minn = min(A[0], 1);
        int tax, tin;
        for (int i = 1; i < n; i++) {
            if (A[i] == 0) {
                maxn = minn = 0;
                res = max(res, maxn);
            } else {
                tax = max(maxn * A[i], minn * A[i]);
                tax = max(tax, A[i]);
                tin = min(maxn * A[i], minn * A[i]);
                tin = min(tin, A[i]);
                maxn = tax;
                minn = tin;
                debug(maxn);
                debug(minn);
            }
            res = max(res, maxn);
        }
        return res;
        
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    int A[4] = {2, 0, -2, 4};
    Solution s;
    debug(s.maxProduct(A, 4));

    return 0;
}

