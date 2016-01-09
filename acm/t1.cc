#include <iostream> 
#include <cstdio> 
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stack>
#include <queue> 
#include <list>
#include <map>
#include <ctime>
#include <set>
#include <unordered_set>
#include <unordered_map>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
typedef long long lld; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 1010
#define PRIME 999983
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    int dp[len + 10][3];
    clr(dp, -1);
    int ans = 0;
    if (len == 0) {
      return 0;
    }

    // 0 stand for buy, 1 stand for sell, 2 stand for nothing
    dp[0][0] = 0;
    dp[0][1] = 0 - prices[0];
    dp[0][2] = 0;
    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
      dp[i][1] = max(dp[i - 1][2] - prices[i], dp[i - 1][1]);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][0]);
      debug(dp[i][0]);
      debug(dp[i][1]);
      debug(dp[i][2]);
      ans = max(dp[i][0], ans);
      ans = max(dp[i][1], ans);
      ans = max(dp[i][2], ans);
    }

    debug(ans);
    return ans;
      
  }

};

int main()
{
#ifdef DEBUG
  freopen("a", "r", stdin);
#endif

  Solution s;
  vector<int> v1{1, 2, 3, 0, 2};

  s.maxProfit(v);
  // s.groupAnagrams(v);
  // s.nextPermutation(v);
  return 0;
}
// 13521173071
