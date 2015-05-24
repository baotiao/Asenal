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
typedef long long lld; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffffffffffff 
#define MIN 0x8000000000000000
#define N 16000010
#define PRIME 999983
public:
    bool valid(TreeNode *root, lld l, lld r)
    {
        if (root == NULL) {
            return true;
        }
        if (root->val >= r || root->val <= l) {
            return false;
        }
        if (!valid(root->left, l, root->val)) {
            return false;
        }
        if (!valid(root->right, root->val, r)) {
            return false;
        }
        return true;
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return valid(root, MIN, MAX);
    }

};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%ld %ld\n", MIN, MAX);

    return 0;
}

