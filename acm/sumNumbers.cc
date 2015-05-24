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

    int sum(TreeNode *t, int num)
    {
        if (t == NULL) {
            return 0;
        }
        if (t->left == NULL && t->right == NULL) {
            return num;
        } else {
            return sum(t->left, t->val + num * 10) + sum(t->right, t->val + num * 10);
        }
    }
    int sumNumbers(TreeNode *root) {
        return sum(root, 0);
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

