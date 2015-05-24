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
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, r = n - 1, mid;
        int resl = -1, resr = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        resl = l;
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        resr = l - 1;
        vector<int> v;
        if (resl >= n || resr <= -1 || resl > resr) {
            v.push_back(-1);
            v.push_back(-1);
        } else {
            v.push_back(resl);
            v.push_back(resr);
        }
        debug(resl);
        debug(resr);
        return v;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    int A[6] = {1, 5};
    s.searchRange(A, 2, 4);


    return 0;
}

