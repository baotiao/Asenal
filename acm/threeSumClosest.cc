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
#define debug(x) cout<<__LINE__<<" "<<#x<<" = "<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN -9999999
#define N 16000010
#define PRIME 999983
public:
    /*
     * 1 2 3 5 8 10
     * 5
     */
    int ans = MAX;
    int res;
    void binary(int l, int r, int now, int tar, vector<int> &num)
    {
        int mid;
        int fl = l;
        int fr = r;
        int val = -(now - tar);
        while (l <= r) {
            mid = (l + r) / 2;
            if (num[mid] < val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        debug(l);
        int tmp;
        if (l == fl) {
            tmp = abs(num[l] + now - tar);
        } else if (l > fr) {
            tmp = abs(num[l - 1] + now - tar);
        } else {
            tmp = min(abs(num[l] + now - tar), abs(num[l - 1] + now - tar));
        }
        if (ans > tmp) {
            ans = tmp;
            debug(ans);
            if (l > fr) {
                res = num[l - 1] + now;
            } else {
                res = num[l] + now;
            }
        }
    }

    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (j + 1 < n) {
                    binary(j + 1, n - 1, num[i] + num[j], target, num);
                }
            }
        }
        debug(res);
        return res;
    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    s.threeSumClosest(v, 100);

    return 0;
}
