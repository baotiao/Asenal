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
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            debug(l)
            debug(mid);
            debug(r);
            if (A[mid] == target) {
                return mid;
            } else if ((A[l] < A[mid] && (A[mid] >= target && target >= A[l])) || (A[l] > A[mid] && (target > A[r] || target < A[mid]))) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    int A[7] = {1};
    debug(s.search(A, 1, 1));

    return 0;
}

