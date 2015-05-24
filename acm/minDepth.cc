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
#define MAX 0x7f7f7f7f 
public:
    int maxd;
    void travel(TreeNode *root, int depth)
    {
        if (root->left == NULL && root->right == NULL) {
            maxd = min(depth, maxd);
        }
        if (root->left != NULL) {
            travel(root->left, depth + 1);
        }
        if (root->right != NULL) {
            travel(root->right, depth + 1);
        }
    }
    int minDepth(TreeNode *root) {
        
        if (root == NULL) {
            return 0;
        }
        maxd = MAX;
        travel(root, 1);
        return maxd;
    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    vector<int> v;
    Solution s;
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    // TreeNode *r4 = new TreeNode(4);
    // TreeNode *r5 = new TreeNode(5);
    r1->right = r2;
    r2->left = r3;
    debug(s.minDepth(r1));
    debug(v.size());
    for (int j = 0; j < v.size(); j++) {
        debug(v[j]);
    }
    printf("\n");

    here;
    return 0;
}

