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
     * 1 2 5 7
     * 1 2 3 5 7
     * 5
     */
    bool binary(int l, int r, int val, vector<int> &num)
    {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (num[mid] < val) {
                l = mid + 1;
            } else if (num[mid] == val) {
                return true;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if (num.size() < 3) {
            return ans;
        }
        sort(num.begin(), num.end());
        vector<vector<int> >::iterator iter;
        int len = num.size();
        for (int i = 0; i < len; i++) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len; j++) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                if (binary(j + 1, len - 1, 0 - num[i] - num[j], num)) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(0 - num[i] - num[j]);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;

    return 0;
}
