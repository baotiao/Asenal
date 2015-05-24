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
#else
#define debug(x)
#endif

class Solution
{
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16010
#define PRIME 999983
public:
    struct node {
        int h;
        int n;
        node() {};
        node (int h_, int n_) : h(h_), n(n_) { };
    };
    
    int largestRectangleArea(vector<int> &height) {
        here;
        int ll = height.size();
        debug(ll);
        debug(ll);
        if (ll == 0) {
            return 0;
        }
        here;
        int l[ll], r[ll];
        stack<node> s;
        s.push(node(height[0], 0));
        node tmp;
        for (int i = 1; i < ll; i++) {
            while (!s.empty() && height[i] < s.top().h) {
                tmp = s.top();
                s.pop();
                l[tmp.n] = i - 1;
            }
            s.push(node(height[i], i));
        }

        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            l[tmp.n] = ll - 1;

        }

        s.push(node(height[ll - 1], ll - 1));
        for (int i = ll - 2; i >= 0; i--) {
            while (!s.empty() && height[i] < s.top().h) {
                tmp = s.top();
                s.pop();
                r[tmp.n] = i + 1;
            }
            s.push(node(height[i], i));
        }
        here
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            r[tmp.n] = 0;
        }
        int maxn = 0;
        for (int i = 0; i < ll; i++) {
            debug(r[i]);
            debug(l[i]);
            maxn = max(maxn, height[i] * (l[i] - r[i] + 1));
        }
        return maxn;
        
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
    debug(s.largestRectangleArea(v));

    return 0;
}
