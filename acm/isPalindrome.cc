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
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983


class Solution {
public:
    bool isPalindrome(string s) {
        string substr = "";
        int slen = s.length();
        for (int i = 0; i < slen; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    substr += (s[i] - 32);
                } else {
                    substr += s[i];
                }
            }
        }
        int len = substr.length();
        if (len == 0) {
            return true;
        }
        int i;
        for (i = 0; i <= len / 2; i++) {
            if (substr[i] != substr[len - 1 - i]) {
                break;
            }
        }
        if (i == (len / 2) + 1) {
            return true;
        } else {
            return false;
        }
        
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    debug(s.isPalindrome("1a2"));
    debug(s.isPalindrome("Aa"));
    debug(s.isPalindrome("A."));
    debug(s.isPalindrome("0k.;r0.k;"));


    return 0;
}

