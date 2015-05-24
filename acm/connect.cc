#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <queue> 
#include <map>
#include <ctime>
#include <set>

typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return ;
        }
        queue<TreeLinkNode *> q;
        TreeLinkNode *t;
        q.push(root);
        TreeLinkNode *pre = NULL;
        int cnt = 1;
        int next = 0;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            if (t->left != NULL) {
                q.push(t->left);
                next++;
            }
            if (t->right != NULL) {
                q.push(t->right);
                next++;
            }
            cnt--;
            if (pre != NULL) {
                pre->next = t;
            }
            if (cnt == 0) {
                cnt = next;
                next = 0;
                t->next = NULL;
                pre = NULL;
            } else {
                pre = t;
            }
        }
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%d %d\n", rand(), rand());

    return 0;
}

