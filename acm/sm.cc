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
  struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
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

  static bool cmp(Interval a, Interval b) {
    return a.start < b.start;
  }
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    if (intervals.size() == 0) {
      return ans;
    }

    if (intervals.size() == 1) {
      return intervals;
    }
    int st, ed;
    sort(intervals.begin(), intervals.end(), cmp);

    st = intervals[0].start;
    ed = intervals[0].end;
    for (int i = 1; i < intervals.size(); i++) {
      if (ed < intervals[i].start) {
        ans.push_back(Interval(st, ed));
        st = intervals[i].start;
        ed = intervals[i].end;
      } else if (ed >= intervals[i].start && ed < intervals[i].end) {
        ed = intervals[i].end;
      } else {
        continue;
      }
    }
    ans.push_back(Interval(st, ed));

    return ans;

  }
};

int main()
{
#ifdef DEBUG
  freopen("a", "r", stdin);
#endif

  return 0;
}
