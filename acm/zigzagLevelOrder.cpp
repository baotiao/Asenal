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
#define N 90
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define MAX 0x7f7f7f7f 
struct flag_node {
    TreeNode *p;
    int flag;
    //flag_node (TreeNode *p_, int flag_) {
    //    p = p_;
    //    flag = flag_;
    //}
};
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector< vector<int> > v;
        if (root == NULL) {
            return v;
        }
        v.resize(1000);
        queue<flag_node> q;
        //q.clear();
        flag_node f;
        f.p = root;
        f.flag = 0;

        q.push(f);
        flag_node tmp;
        int now_flag = -1;
        int index = -1;
        flag_node l, r;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            debug(tmp.p->val);
            if (tmp.flag != now_flag) {
                now_flag = tmp.flag;
                index++;
            }
            debug(index);
            if (index % 2) {
                v[index].insert(v[index].begin(), tmp.p->val);
            } else {
                v[index].push_back(tmp.p->val);
            }
            if (tmp.p->left != NULL) {
                l.p = tmp.p->left;
                l.flag = tmp.flag + 1;
                q.push(l);
            }
            if (tmp.p->right != NULL) {
                r.p = tmp.p->right;
                r.flag = tmp.flag + 1;
                q.push(r);
            }
            
        }
        index++;
        v.resize(index);
        return v;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    vector< vector<int> >v;
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
    v = s.zigzagLevelOrder(r1);
    debug(v.size());
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            debug(v[i][j]);
        }
        printf("\n");
    }

    here;
    return 0;
}

