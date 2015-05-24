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
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:

    bool travel(TreeLinkNode *p, TreeLinkNode *right) {
        if (p != NULL) {
            p->next = right;
        }
    }
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        if (root == NULL) {
            return ;
        }
        travel(root, NULL);
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution *s = new Solution();
    TreeLinkNode *r1 = new TreeLinkNode(1);
    TreeLinkNode *r2 = new TreeLinkNode(2);
    TreeLinkNode *r3 = new TreeLinkNode(3);
    TreeLinkNode *r4 = new TreeLinkNode(4);
    TreeLinkNode *r5 = new TreeLinkNode(5);
    TreeLinkNode *r6 = new TreeLinkNode(6);
    TreeLinkNode *r7 = new TreeLinkNode(5);
    TreeLinkNode *r8 = new TreeLinkNode(6);

    r1->left = r2;
    r1->right = r3;
    //r3->left = r4;

    //r3->right = r5;
    s->connect(r1);
    return 0;
}

