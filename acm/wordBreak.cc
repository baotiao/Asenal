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
#include <unordered_set>

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
	bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.length();
		int dp[len + 10][len + 10];
		clr(dp, 0);
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
					dp[i][j] = 1;
					/*
					 * debug(i);
					 * debug(j);
					 */
				}
			}
		}
		debug(len);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j + i < len; j++) {
				if (dp[j][j + i] == 1) {
					continue;
				}
				debug(i);
				debug(j);
				for (int k = j; k < j + i; k++) {
					debug(k);
					debug(dp[i][k]);
					debug(dp[k + 1][j + i]);
					if (dp[j][k] == 1 && dp[k + 1][j + i] == 1) {
						dp[j][j + i] = 1;
						break;
					}
				}
			}
		}
		debug(dp[0][len - 1]);
		if (dp[0][len - 1] == 1){
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

	unordered_set<std::string> d;
	d.insert("a");
	d.insert("b");

	s.wordBreak("ab", d);

    return 0;
}
