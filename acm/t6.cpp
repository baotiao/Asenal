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

    void buildBST(TreeNode *fa, int flag, vector<int> &num, int left, int right)
    {
        if (left > right) {
            return ;
        }
        if (left == right) {
            TreeNode *tmp = new TreeNode(num.at(left));
            if (flag == 0) {
                fa->left = tmp;
            } else {
                fa->right = tmp;
            }
            return ;
        }
        int mid = (left + right) / 2;
        TreeNode *tmp = new TreeNode(num.at(mid));
        if (flag == 0) {
            fa->left = tmp;
        } else {
            fa->right = tmp;
        }
        if (left <= mid - 1) {
            buildBST(tmp, 0, num, left, mid - 1);
        }
        if (mid + 1 <= right) {
            buildBST(tmp, 1, num, mid + 1, right);
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        

        int len = num.size();

        if (len == 0) {
            return NULL;
        }

        int mid = (0 + len) / 2;
        TreeNode *head = new TreeNode(num.at(mid));
        
        buildBST(head, 0, num, 0, mid - 1);
        buildBST(head, 1, num, mid + 1, len - 1);
        return head;
    }
};
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    vector<int> v;
    v.push_back(0);
    Solution s;
    s.sortedArrayToBST(v);
    return 0;
}

