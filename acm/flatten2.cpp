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
#include<queue>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
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
public:

    TreeNode *pre_travel(TreeNode *p) {
        //debug(p->val);
        if (p->left == NULL && p->right == NULL) {
            return p;
        }
        TreeNode *l = NULL;
        TreeNode *p_r = p->right;
        if (p->left != NULL) {
            l = pre_travel(p->left);
            l->right = p->right;
            p->right = p->left;
            p->left = NULL;
        }
        if (p_r == NULL) {
            return l;
        }

        TreeNode *r = NULL;
        if (p_r != NULL) {
            r = pre_travel(p_r);
        }
        return r;
    }

    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        if (root == NULL) {
            return;
        }
        pre_travel(root);
        return;
    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution *s = new Solution();
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r5 = new TreeNode(5);
    TreeNode *r6 = new TreeNode(6);

    TreeNode *head = r1;
    r1->left = r2;
    //r1->right = r5;
    r2->left = r3;
    //r2->right = r4;
    //r5->right = r6;

    s->flatten(r1);

    //sleep(100);
    //r1 = head;
    while (r1 != NULL) {
        debug(r1->val);
        r1 = r1->right;
    }
    return 0;
}

