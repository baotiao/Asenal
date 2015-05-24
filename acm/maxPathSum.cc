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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    int f = 0, s = 0;
    int maxn = MIN;
    int flag = 0;
    int fmax = MIN;
    int dfs(TreeNode *t)
    {
        if (t == NULL) {
            return 0;
        }
        if (t->val > 0) {
            flag = 1;
        }
        fmax = max(fmax, t->val);
        int l = dfs(t->left) + t->val;
        int r = dfs(t->right) + t->val;
        f = max(l, r);
        s = min(l, r);
        maxn = max(maxn, f + s - t->val);
        maxn = max(maxn, f);
        return max(f, 0);
    }
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        if (flag == 1) {
            return maxn;
        } else {
            return fmax;
        }
    }

};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%d %d\n", rand(), rand());
    Solution s;

    return 0;
}

