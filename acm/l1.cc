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
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif

class Solution
{
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
#define MIN -9999999
#define N 16000010
#define PRIME 999983
public:

    int rob(vector<int>& nums)
    {
        if (nums.size() <= 0) {
            return 0;
        }
        int maxMoney = nums[0];
        int notRob = 0;
        int tmp;
        for (int i = 1; i < nums.size(); i++) {
            tmp = notRob;
            notRob = max(notRob, maxMoney);
            maxMoney = tmp + nums[i];
        }
        return max(notRob, maxMoney);
    }
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;



    return 0;
}
