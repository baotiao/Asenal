#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<stack>
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
struct stack_node {
    TreeNode *p;
};
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> v;
        if (root == NULL) {
            return v;
        }
        stack<TreeNode*> s;
        TreeNode *tmp = root;
        while (!s.empty() || tmp) {
            if (tmp != NULL) {
                s.push(tmp);
                tmp = tmp->left;
            } else {
                tmp = s.top();
                s.pop();
                debug(tmp->val);
                v.push_back(tmp->val);
                //if (tmp->right != NULL) {
                tmp = tmp->right;
                //}
            }

        }
        return v;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution s;
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r5 = new TreeNode(5);
    r1->left = r2;
    r1->right = r3;
    r3->left = r4;
    r4->right = r5;
    vector<int> v = s.inorderTraversal(r1);
    debug(v.size());
    for (int i = 0; i < v.size(); i++) {
        debug(v[i]);
    }
    return 0;
}

