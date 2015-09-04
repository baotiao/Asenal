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
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
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
public:
  vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {

    vector<pair<int, int> > ans;

    deque<pair<int, int> > dq;

    pair<int, int> f, s;
    for (int i = 0; i < buildings.size(); i++) {
      f.first = buildings[i][0];
      f.second = building[i][2];

      s.first = buildings[i][1];
      s.second = buildings[i][2];

      while (!dq.empty() || (f.first > dq.front().first && f.second > dq.front().first)) {
        dq.pop_front();
      }
      dq.push_front(f);

    }

  }
};

int main()
{
#ifdef DEBUG
  freopen("a", "r", stdin);
#endif


  return 0;
}
