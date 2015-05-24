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
    bool check(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return (check(p->left, q->left) && check(p->right, q->right));
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }

        return check(p, q);
    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    //int T;
    //Solution *s = new Solution();
    //TreeNode *r1 = new TreeNode(3);
    //TreeNode *r2 = new TreeNode(9);
    //TreeNode *r3 = new TreeNode(20);
    //TreeNode *r4 = new TreeNode(15);
    //TreeNode *r5 = new TreeNode(7);
    //TreeNode *r6 = new TreeNode(6);
    //TreeNode *r7 = new TreeNode(5);
    //TreeNode *r8 = new TreeNode(6);

    //r1->left = r2;
    ////r1->right = r3;
    ////r3->left = r4;

    ////r3->right = r5;
    //vector<vector<int> > v = s->levelOrderBottom(r1);
    //for (int i = 0; i < v.size(); i++) {
    //    debug(v[i].size());
    //    for (int j = 0; j < v[i].size(); j++) {
    //        printf(" %d ", v[i][j]);
    //    }
    //    printf("\n");
    //}
    return 0;
}

