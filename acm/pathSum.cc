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

    void get_sum(TreeNode *t, vector<vector<int> > &r, vector<int> v, int now, int sum)
    {
        if (t == NULL) {
            return ;
        }
        if (t->left == NULL && t->right == NULL) {
            if (now + t->val == sum) {
                vector<int> v1 = v;
                v1.push_back(t->val);
                r.push_back(v1);
            }
        } else {
            vector<int> v1 = v;
            v1.push_back(t->val);
            get_sum(t->left, r, v1, now + t->val, sum);
            get_sum(t->right, r, v1, now + t->val, sum);
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> v1;

        get_sum(root, res, v1, 0, sum);

        return res;
    }

};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%d %d\n", rand(), rand());
    Solution s;
    TreeNode *r = new TreeNode(1);
    vector<vector<int> > v = s.pathSum(r, 1);


    return 0;
}

