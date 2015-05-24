#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<map>
#include<ctime>
#include<set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
#define N 90
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define MAX 0x7f7f7f7f 
public:
    int high;
    int low;
    int getInfo(TreeNode *root, int height)
    {

        int l;
        if (root->left != 0) {
            l = getInfo(root->left, height + 1);
        } else {
            l = height;
        }
        int r;
        if (root->right != 0) {
            r = getInfo(root->right, height + 1);
        } else {
            r = height;
        }
        if (l == -1 || r == -1 || abs(l - r) > 1) {
            return -1;
        }
        return max(l, r);
    }

    bool isBalanced(TreeNode *root) 
    {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (root == NULL) {
            return true;
        }
        
        high = 0;
        low = 100000;
        int height = 1;
        if (getInfo(root, height) == -1) {
            return false;
        } else {
            return true;
        }
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution *s = new Solution();
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r5 = new TreeNode(5);
    TreeNode *r6 = new TreeNode(6);
    TreeNode *r7 = new TreeNode(5);
    TreeNode *r8 = new TreeNode(6);

    r1->left = r2;
    r1->right = r3;
    r3->left = r4;

    r3->right = r5;
    bool ans = s->isBalanced(r1);
    debug(ans);
    return 0;
}

