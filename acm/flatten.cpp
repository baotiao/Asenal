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
public:
    TreeNode *travel(TreeNode *p, bool flag)
    {
        if (p == NULL) {
            return NULL;
        }
        if (p->left == NULL && p->right == NULL) {
            return p;
        }
        TreeNode *l, *r;
        if (p->left != NULL) {
            l = travel(p->left, 0);
        } else {
            l = NULL;
        }

        if (p->right != NULL) {
            r = travel(p->right, 1);
        } else {
            r = NULL;
        }

        if (l != NULL && r != NULL) {
            //TreeNode *t = p->right;
            l->right = p->right;
            p->right = p->left;
            p->left = NULL;
        } else if (l == NULL && r != NULL) {
            //p->right = r;
            p->left = NULL;
        } else if (l != NULL && r == NULL) {
            p->right = p->left;
            l->right = NULL;
        } else {
            return p;
        }
        if (flag == 0) {
            if (r == NULL) {
                return l;
            }
            return r;
        } else {
            return p;
        }
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL) {
            return ;
        }
        if (root->right != NULL && root->left == NULL && root->right->left == NULL && root->right->right == NULL) {
            return ;
        }
        travel(root, 0);
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
    //TreeNode *r3 = new TreeNode(3);
    //TreeNode *r4 = new TreeNode(4);
    //TreeNode *r5 = new TreeNode(5);
    //TreeNode *r6 = new TreeNode(6);

    r1->right = r2;
    //r1->left = NULL;
    //r1->left = r3;
    //r1->right = r5;
    //r2->left = r3;
    //r2->right = r4;
    //r5->right = r6;

    TreeNode *head = r1;
    while (r1 != NULL) {
        debug(r1->val);
        r1 = r1->right;
    }
    here;
    s->flatten(head);

    r1 = head;
    while (r1 != NULL) {
        debug(r1->val);
        r1 = r1->right;
    }
    return 0;
}

