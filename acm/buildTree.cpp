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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
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
public:
    TreeNode* buildTravel(int l, int r, vector<int> &preorder, vector<int> &inorder, int pre_num) {
        if (l == r) {
            TreeNode *p = new TreeNode(inorder[l]);
            p->left = p->right = NULL;
            return p;
        }
        TreeNode *p = new TreeNode(preorder[pre_num]);
        int i;
        for (i = l; i <= r; i++) {
            if (inorder[i] == preorder[pre_num]) {
                break;
            }
        }
        printf("%d %d %d %d\n", l, r, pre_num, i);
        //debug(pre_num);
        if (l >= i) {
            p->left = NULL;
        } else {
            p->left = buildTravel(l, i - 1, preorder, inorder, pre_num + 1);
        }

        if (i >= r) {
            p->right = NULL;
        } else {
            p->right = buildTravel(i + 1, r, preorder, inorder, pre_num + 1 + i);
        }
        return p;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        if (preorder.size() != inorder.size()) {
            return NULL;
        }
        int len = preorder.size();

        return buildTravel(0, len - 1, preorder, inorder, 0);
        
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution *s = new Solution();
    int a[200] = {-77,24,-74,84,93,28,83,6,95,58,59,66,22,-3,-66,-68,-22,3,-80,-79,-85,17,32,9,-88,-99,14,-60,13,-93,-63,91,82,21,26,-11,-32,
        -16,-100,-94,-31,-62,-89,49,-9,-8,87,-33,-81,80,0,69,-7,52,67,-5,-65,31,-30,37,-57,27,23,38,-28,7,-82,-42,11,-55,-36,-58,-24,89,56,73,41,18,-87,-70,4,-64,20,-52,-39,79,19,30,65,25,-71,-76,-1,62,-69,98,39,-25,-73,70,88,-17,-20,-75,55,34,57,81,-10,94,48,-35,5,-23,-44,40,-51,-61,-13,-86,63,71,-97,45,43,51,75,33,-34,92,47,-78,85,-26,97,-29,-92,-83,-59,74,96,68,77,16,-4,10,60,64,-21,-2,1,-91,86,46,76,-37,-19,-96,36,-98,29,-72,61,50,15,-95,-40,-43,-53,90,-15,-48,-27,-90,-54,72,-50,-49,-18,78,54,35,-38,99,44,-67,53,-12,-41,2,8,-14,-84,-56,-6,12,-45,42,-47,-46};
    int b[200] = {93,28,84,83,-74,59,58,66,-66,-3,-79,-80,3,-22,-68,22,-85,-99,14,-88,9,32,17,-60,95,-93,82,21,91,-63,26,13,-16,-32,-11,-100,6,-62,49,-89,-31,87,-8,69,0,80,-7,-81,-65,-5,67,-30,31,52,-33,37,-57,-9,7,-28,-42,
        -82,38,-55,11,23,-36,27,56,89,73,-24,41,-58,-70,-87,20,-64,-52,4,18,-94,19,30,-76,-1,-71,62,-69,25,-73,-25,70,39,88,98,-20,-17,65,55,-75,79,34,-39,48,94,-23,5,-44,-35,40,-10,-61,-51,-13,81,63,-97,71,-86,57,45,24,-34,85,97,-26,-78,-83,-92,74,-59,96,-29,68,47,77,92,10,-4,16,60,33,-21,1,86,76,46,-37,-91,-2,64,75,51,-19,-96,43,-98,29,61,-72,50,36,-95,-40,-43,15,90,-15,-53,-77,-54,-90,-49,-50,72,-27,35,54,-38,78,-67,44,53,99,-41,-12,-18,8,2,-48,-56,-84,-14,-45,12,42,-6,-46,-47};
    vector<int> p;
    vector<int> i;
    //p.push_back(1);
    //p.push_back(2);
    //p.push_back(4);
    //p.push_back(3);
    //p.push_back(5);
    //p.push_back(6);


    //i.push_back(2);
    //i.push_back(4);
    //i.push_back(1);
    //i.push_back(5);
    //i.push_back(3);
    //i.push_back(6);
    for (int j = 0; j < 200; j++) {
        p.push_back(a[j]);
        i.push_back(b[j]);
    }
    TreeNode *root = s->buildTree(p, i);
    //debug(root->val);
    //debug(root->left->val);
    //debug(root->right->val);
    //debug(root->left->right->val);
    //debug(root->right->left->val);
    //debug(root->left->left->right->val);
    return 0;
}

