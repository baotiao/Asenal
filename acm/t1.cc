#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stack>
#include <queue> 
#include <map>
#include <ctime>
#include <set>
typedef long long lld; 
using namespace std; 
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
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
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
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
public:
  int DfsTree(TreeNode* t, int k, int &ans) {
    if (ans != -1) {
      return 0;
    }
    int cnt = 0;
    if (t->left != NULL) {
      cnt = DfsTree(t->left, k, ans);
    }
    if (cnt == k - 1) {
      ans = t->val;
    }
    int cnt1 = 0;
    if (t->right != NULL) {
      cnt1 = DfsTree(t->right, k - cnt - 1, ans);
    }
    return cnt + cnt1;
  }

  int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    DfsTree(root, k, ans);
    return ans;
  }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
    // s.calculate("1");

    return 0;
}

