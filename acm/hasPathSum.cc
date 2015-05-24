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
#define N 16000010
#define PRIME 999983
public:
    bool travel(TreeNode *t, int now, int sum)
    {
        if (t->left == NULL && t->right == NULL && now == sum) {
            return true;
        }
        if (t->left != NULL) {
            if (travel(t->left, now + t->left->val, sum)) {
                return true;
            }
        }
        if (t->right != NULL) {
            if (travel(t->right, now + t->right->val, sum)) {
                return true;
            }
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        return travel(root, root->val, sum);
    }

};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%d %d\n", rand(), rand());

    return 0;
}

