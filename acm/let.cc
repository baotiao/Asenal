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
#define debug(x) cout<<__LINE__<<" "<<#x<<" = "<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN -9999999
#define N 16000010
#define PRIME 999983
public:
    int strStr(char *haystack, char *needle) {
        int lh = strlen(haystack);
        int ln = strlen(needle);
        if (ln > lh) {
            return -1;
        }
        int next[ln + 10];
        int i = 0;
        int j = -1;
        /*
         * abcabcabcd
         * 0001234560
         * aabcaabdaabc
         * 010012301234
         * abcdabce
         * 00001230
         * -1 -1 -1 -1 0 1 2 -1
         * abababcabcab
         * 001234012012
         * -1 -1 0 1 2 3 -1 0 1 -1 0 1
         */

        next[0] = -1;
        j = 0;
        for (int i = 1; i < ln; i++) {
            debug(j);
            debug(next[i - 1]);
            if (needle[i] == needle[j]) {
                debug(i);
                next[i] = j;
                j++;
            } else if (j == 0) {
                next[i] = -1;
            } else {
                // 1
                j = next[j - 1] + 1;
                i--;
            }
        }
        for (int i = 0; i < ln; i++) {
            debug(next[i]);
        }
        i = 0;
        j = 0;
        while (i < lh && j < ln) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = next[j - 1] + 1;
                }
            }
        }
        if (j == ln) {
            return i - ln;
        } else {
            return -1;
        }
    }

};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
    // ababcd
    // -1 -1 0 1 -1 -1
    debug(s.strStr("baabbaaaaaaabbaaaaabbabbababaabbabbbbbabbabbbbbbabababaabbbbbaaabbbbabaababababbbaabbbbaaabbaababbbaabaabbabbaaaabababaaabbabbababbabbaaabbbbabbbbabbabbaabbbaa", "bbaaaababa"));

    return 0;
}
