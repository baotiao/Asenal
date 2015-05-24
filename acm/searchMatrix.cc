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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int m, n;
        n = matrix.size();
        m = matrix[0].size();
        debug(m);
        debug(n);
        int l = 0, r = (m * n) - 1, mid;
        int num;
        while (l <= r) {
            mid = (l + r) / 2;
            debug(mid);
            num = matrix[mid / m][mid % m];
            debug(num);
            if (num == target) {
                return true;
            } else if (num < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    vector< vector<int> > v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v.push_back(v1);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(11);
    v2.push_back(16);
    v2.push_back(20);
    v.push_back(v2);

    vector<int> v3;
    v3.push_back(23);
    v3.push_back(30);
    v3.push_back(34);
    v3.push_back(50);
    v.push_back(v3);
    debug(s.searchMatrix(v, 35));


    return 0;
}

