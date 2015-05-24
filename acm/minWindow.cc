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
    int getNum(char c) {
        return (1 << (c - 'a'));
    }
    string minWindow(string S, string T) {
        int ls = S.length();
        int lt = T.length();
        int arrt[256] = {0};
        int arrs[256] = {0};
        for (int i = 0; i < lt; i++) {
            arrt[T[i]]++;
        }

        int l = MAX;
        string ans = ""; 
        int cnt = 0;
        for (int i = 0, s = 0; i < ls; i++) {
            if (arrs[S[i]] < arrt[S[i]]) {
                cnt++;
            }
            if (arrt[S[i]] != 0) {
                arrs[S[i]]++;
            }
            debug(lt);
            debug(cnt);
            if (cnt == lt) {
                int j;
                debug(s);
                for (j = s; j <= i; j++) {
                    if (arrt[S[j]] == 0) {
                        continue;
                    }
                    if (arrs[S[j]] == arrt[S[j]]) {
                        cnt--;
                        arrs[S[j]]--;
                        break;
                    } else {
                        arrs[S[j]]--;
                    }
                }
                debug(j);
                j = min(j, i);
                if (l > i - j + 1) {
                    l = i - j + 1;
                    debug(i);
                    debug(j);
                    ans = S.substr(j, i - j + 1);
                    debug(ans);
                }
                s = j + 1;
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
    string res = s.minWindow("bdab", "ab");
    debug(res);

    return 0;
}

