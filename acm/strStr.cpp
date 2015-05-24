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
public:
    int jump[160000];
    void init_jump(char *needle) 
    {
        jump[0] = -1;
        int k = -1;
        int hayLen = strlen(needle);
        int now = -1;
        for (int i = 1; i < hayLen; i++) {
            if (needle[jump[i - 1] + 1] == needle[i]) {
                jump[i] = jump[i - 1] + 1;
            } else {
                now = jump[i - 1];
                while (now != -1 && needle[jump[now] + 1] != needle[i]) {
                    now = jump[now];
                }
                jump[i] = now;
            }
        }
    }

    char *match(char *haystack, char *needle) 
    {
        int hayLen = strlen(haystack);
        int needLen = strlen(needle);
        int i = 0, j = 0;
        int now;
        while (i < hayLen && j < needLen) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = jump[j - 1] + 1;
                }
            }
        }
        if (j == needLen) {
            return haystack + i - needLen;
        } else {
            return NULL;
        }
    }
    char *strStr(char *haystack, char *needle) 
    {
        if (haystack == NULL || needle == NULL) {
            return NULL;
        }
        int hayLen = strlen(haystack);
        int needLen = strlen(needle);
        if (needLen == 0) {
            return haystack;
        }
        if (hayLen == 0) {
            return NULL;
        }
        if (hayLen < needLen) {
            return NULL;
        }
        init_jump(needle);
        return match(haystack, needle);
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution s;
    char *haystack = "bbbbababbbaabbba";
    char *needle = "abb";
    //s.init_jump(needle);
    //s.match(haystack, needle);
    printf("%s\n", s.strStr(haystack, needle));

    return 0;
}

