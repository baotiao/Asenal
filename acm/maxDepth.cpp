#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int dfs(TreeNode *p) {
        if (p == NULL) {
            return 0;
        }
        return max(dfs(p->left), dfs(p->right)) + 1;
    }

    int maxDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (root == NULL) {
            return 0;
        }
        return dfs(root);
        
    }
};
int main()
{
    Solution s;
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    
    r1->left = r2;
    r1->right = r3;
    printf("%d\n", s.maxDepth(r1));
    
    return 0;
}
