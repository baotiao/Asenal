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
#include <stack>

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
    string simplifyPath(string path)
    {
        if (path == "") {
            return "";
        }
        string p = "";
        char c = 'a';
        for (int i = 0; i < path.length(); i++) {
            if (c == '/' && path[i] == '/') {
                continue;
            } else {
                p += path[i];
                c = path[i];
            }
        }
        debug(p.length());
        debug(path);
        debug(p.length());
        string p1 = "";
        
        for (int i = 0; i < p.length(); i++) {
            if ((i == 0 || p[i - 1] == '/') && p[i] == '.' && p[i + 1] == '/' && i + 1 < p.length()) {
                i++;
            } else {
                p1 += p[i];
            }
        }
        
        debug(p1.length());

        stack<int> s;
        while (!s.empty()) {
            s.pop();
        }

        debug(p1);
        debug(p1.length());
        for (int i = 0; i < p1.length(); i++) {
            if ((i + 2 < p1.length()) && p1[i] == '/' && p1[i + 1] == '.' && p1[i + 2] == '.' && ((i + 3 < p1.length() && p1[i + 3] == '/') || i + 3 >= p1.length())) {
                if (!s.empty()) {
                    s.pop();
                }
                here;
                i += 2;
            } else if (p1[i] == '/') {
                debug(i);
                s.push(i);
            }
        }
        string ans = "";
        int tmp;
        stack<int>s1;
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            s1.push(tmp);
        }

        while (!s1.empty()) {
            tmp = s1.top();
            s1.pop();
            
            debug(tmp);

            if (tmp == p1.length() - 1) {
                continue;
            }
            if (tmp == p1.length() - 2 && p1[tmp] == '/' && p1[tmp + 1] == '.') {
                continue;
            }
            ans += p1[tmp];
            for (int i = tmp + 1; i < p1.length(); i++) {
                if (p1[i] == '/') {
                    break;
                }
                ans += p1[i];
            }
        }

        debug(ans.length());
        if (ans == "" || ans == "/.") {
            ans = "/";
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
    debug(s.simplifyPath("/.../"));
    // debug(s.simplifyPath(""));
    // debug(s.simplifyPath("/home/"));
    // debug(s.simplifyPath("/a/./b/../../c/"));
    // debug(s.simplifyPath("/home//foo/"));

    return 0;
}

