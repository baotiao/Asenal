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

class Solution {
public:
    string addBinary(string a, string b) {
        bool flag = false;
        string res = "";
        int lena = a.length();
        int lenb = b.length();
        int len = min(lena, lenb);
        for (int i = len - 1; i >= 0; i--) {
            if (a[i] == '0' && b[i] == '0') {
                if (flag == 0) {
                    

    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    vector<int> v;
    Solution s;
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    // TreeNode *r4 = new TreeNode(4);
    // TreeNode *r5 = new TreeNode(5);
    r1->right = r2;
    r2->left = r3;
    debug(s.minDepth(r1));
    debug(v.size());
    for (int j = 0; j < v.size(); j++) {
        debug(v[j]);
    }
    printf("\n");

    here;
    return 0;
}

