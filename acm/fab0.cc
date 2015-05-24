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
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983

bool cmp(char a, char b)
{
    return a > b;
}

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    int cas = 1;
    while (T--) {
        string str;
        printf("Case #%d: ", cas++);
        cin >> str;
        string s1 = str;
        string s2 = str;
        string mins = str;
        sort(s1.begin(), s1.end(), cmp);
        sort(s2.begin(), s2.end());
        int len = str.length();
        int f = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] != s1[i]) {
                for (int j = len - 1; j >= i; j--) {
                    if (str[j] == s1[i]) {
                        swap(str[i], str[j]);
                        f = 1;
                        break;
                    }
                }
                if (f == 1) {
                    break;
                }
            }
        }
        int i = 0, j = 0;
        f = 0;
        while (i < len && j < len) {
            if (s2[j] == '0') {
                j++;
                continue;
            }
            if (mins[i] == s2[j]) {
                i++;
                j++;
                continue;
            }
            if (i != 0 && j != 0 && i != j) {
                for (int k = len - 1; k >= 0; k--) {
                    if (mins[k] == '0') {
                        swap(mins[i], mins[k]);
                        break;
                    }
                }
                break;
            } else{
                for (int k = len - 1; k >= 0; k--) {
                    if (mins[k] == s2[j]) {
                        swap(mins[i], mins[k]);
                        break;
                    }
                }
                break;
            }
        }
        printf("%s %s\n", mins.c_str(), str.c_str());
    }

    return 0;
}

