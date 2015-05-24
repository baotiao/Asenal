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
    TreeNode *build_tree(vector<int> &num, int l, int r)
    {
        int m = (l + r + 1) / 2;
        //sleep(1);
        //debug(l);
        //debug(m);
        //debug(r);
        TreeNode *node = new TreeNode(num[m]);
        if (l < m) { 
            node->left = build_tree(num, l, m - 1);
        }
        if (m < r) {
            node->right = build_tree(num, m + 1, r);
        }
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        
        int len = num.size();
        if (len == 0) {
            return NULL;
        }
        return build_tree(num, 0, len - 1);
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        v.push_back(i);
    }
    Solution s;
    TreeNode *p = s.sortedArrayToBST(v);

    debug(p->val);
    while (p->left != NULL) {
        printf("%d\n", p->val);
        p = p->left;
        debug(p->val);
    }
    
    return 0;
}

