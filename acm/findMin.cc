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
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME))
#define MAX 0x7fffffff
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983

class Solution {
public:
    int bSearch(vector<int> &num, int l, int r)
    {
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (num[l] < num[r]) {
                r = l;
            } else {
                if (num[l] < num[mid]) {
                    l = mid + 1;
                } else if (num[l] > num[mid]) {
                    r = mid;
                } else {
                    l = l + 1;
                }
            }
        }
        return num[l];
    }
    int findMin(vector<int> &num)
    {
        if (num.size() == 0) {
            return 0;
        }
        if (num.size() == 1) {
            return num[0];
        }

        return bSearch(num, 0, num.size() - 1);

    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    vector<int>v;
    v.push_back(2);
    v.push_back(1);
    debug(s.findMin(v));

    return 0;
}

