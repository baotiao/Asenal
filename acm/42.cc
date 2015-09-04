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
#include <stack>

typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif

class Solution
{
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN -9999999
#define N 16000010
#define PRIME 999983
public:
    int trap(vector<int>& height) {
        int len = height.size();
        stack<pair<int, int> > st;
        int sum = 0;
        int curSum;
        vector<pair<int, int> > vp;
        int pLen;

        for (int i = 0; i < len; i++) {
            curSum = 0;

            vp.clear();
            while (!st.empty() && height[i] >= st.top().second) {
                vp.push_back(st.top());
                st.pop();
            }

            pLen = vp.size();
            debug(pLen);

            if (pLen > 0) {
                if (!st.empty()) {
                    curSum = (i - st.top().first - 1) * height[i];
                } else {
                    curSum = (i - vp[pLen - 1].first - 1) * vp[pLen - 1].second;
                }
                debug(curSum);


                for (int i = 0; i < pLen; i++) {
                    debug(vp[i].first);
                }
                int tmpSum;
                for (int i = 0; i < pLen - 1; i++) {
                    debug(vp[i].first);
                    debug(vp[i + 1].first);
                    tmpSum = (vp[i].first - vp[i + 1].first) * vp[i].second;
                    debug(tmpSum);

                    curSum -= tmpSum;
                }
                if (!st.empty()) {
                    tmpSum = (vp[pLen - 1].first - st.top().first) * vp[pLen - 1].second;
                    curSum -= tmpSum;
                }


                sum += curSum;
            }
            st.push(make_pair(i, height[i]));
        }

        debug(sum);
        return sum;

    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    s.trap(v);

    int arr1[] = {4, 2, 3};
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    s.trap(v1);

    return 0;
}
