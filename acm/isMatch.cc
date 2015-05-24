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
    int lens;
    int lenp;
    bool check(const char *p, int pi)
    {
        for (int i = pi; i < lenp; i++) {
            if (p[pi] != '*') {
                return false;
            }
        }
        return true;
    }
    bool dfs(const char *s, const char *p, int si, int pi, char n)
    {
        if (si == lens) {
            return check(p, pi);
        }
        if (si >= lens || pi >= lenp) {
            return false;
        }
        if (s[si] == p[pi]) {
            if (dfs(s, p, si + 1, pi + 1, n)) {
                return true;
            }
        } else if (p[pi] == '?') {
            if (dfs(s, p, si + 1, pi + 1, n)) {
                return true;
            }
        } else if (p[pi] == '*') {
            if (n == '*') {
                if (dfs(s, p, si + 1, pi, s[si])) {
                    return true;
                }
            } else {
                if (n == s[si]) {
                    if (dfs(s, p, si + 1, pi, n)) {
                        return true;
                    }
                }
            }
            if (dfs(s, p, si, pi + 1, '*')) {
                return true;
            }
        }
        return false;
    }
    bool isMatch(const char *s, const char *p)
    {
        lens = strlen(s);
        lenp = strlen(p);
        return dfs(s, p, 0, 0, '*');
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;

    debug(s.isMatch("aa", "*"));
    return 0;
}

