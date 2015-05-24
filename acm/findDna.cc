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
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> ans;
        if (len <= 0) {
            return ans;
        }
        set<string> st;
        set<string>::iterator iter;
        string str;
        for (int i = 0; i + 10 < len; i++) {
            iter = st.find(s.substr(i, 10));
            if (iter == st.end()) {
                st.insert(s.substr(i, 10));
            } else {
                ans.push_back(s.substr(i, 10));
            }
        }
        return ans;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
    vector<string> v = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

    cout << v[0] << endl;
    return 0;
}

