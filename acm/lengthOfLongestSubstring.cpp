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
#define PRIME 999983

class Solution {
#define N 90
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        

        int len = s.length();
        if (len == 0 || len == 1) {
            return len;
        }

        queue<int> q;
        int flag[N];
        memset(flag, 0, sizeof(flag));
        int ans = 1;
        flag[s[0] - 'a'] = 1;
        q.push(s[0] - 'a');
        debug(len);
        for (int i = 1; i < len; i++) {
                debug(s[i] - 'a');
            if (flag[s[i] - 'a'] == 1) {
                debug(q.size());
                ans = max(ans, (int)q.size());
                while (!q.empty() && q.front() != s[i] - 'a') {
                    flag[q.front()] = 0;
                    q.pop();
                }
                q.pop();
                q.push(s[i] - 'a');
            } else {
                q.push(s[i] - 'a');
                flag[s[i] - 'a'] = 1;
            }
        }
        ans = max(ans, (int)q.size());
        return ans;
    }
};
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution s;
    string test = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    debug(s.lengthOfLongestSubstring(test));
    return 0;
}

