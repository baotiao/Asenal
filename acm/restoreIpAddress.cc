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

    vector<string> ans;
    int len;
    bool check(string str)
    {
        if (str.length() > 3 || str.length() == 0) {
            return false;
        }
       int num = atoi(str.c_str());
       if (num >= 0 && num <= 9 && str.length() == 1) {
           return true;
       } else if (num >= 10 && num <= 99 && str.length() == 2) {
           return true;
       } else if (num >= 100 && num <= 255 && str.length() == 3) {
           return true;
       }
       return false;
    }
    void dfs(string s, int f, int t, int n, string res)
    {
        if (n == 3) {
            string str = s.substr(f);
            if (check(str)) {
                ans.push_back(res + str);
            }
            return ;
        }
        if (f >= len) {
            return ;
        }
        string str = s.substr(t, f + 1 - t);
        if (check(str)) {
            dfs(s, f + 1, f + 1, n + 1, res + str + string("."));
        }
        dfs(s, f + 1, t, n, res);
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        len = s.length();
        if (len > 12) {
            return ans;
        }
        dfs(s, 0, 0, 0, ""); 
        return ans;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    return 0;
}

