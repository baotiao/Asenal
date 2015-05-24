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
#define N 16000010
#define PRIME 999983

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int valsLen = intervals.size();
        if (valsLen == 0) {
            vector<Interval> v;
            v.push_back(newInterval);
            return v;
        }
        int flag = 0;
        int lf = -1, rf = valsLen;
        Interval tmp(0, 0);
        int place = 0;
        for (int i = 0; i < valsLen; i++) {
            if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
                lf = i;
                break;
            }
        }
        for (int i = 0; i < valsLen; i++) {
            if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) {
                rf = i;
                break;
            }
        }
        if (lf == -1 && rf == valsLen) {
            if (newInterval.end < intervals[0].start) {
                intervals.insert(intervals.begin(), newInterval);
            } else {
                intervals.push_back(newInterval);
            }
        } else {
            if (lf == -1) {
                tmp.start = newInterval.start;
            } else {
                tmp.start = min(newInterval.start, intervals[lf].start);
            }
            if (rf == valsLen) {
                tmp.end = newInterval.end;
            } else {
                tmp.end = max(newInterval.end, intervals[rf].end);
            }
            for (int i = max(lf, 0); i <= min(rf, valsLen - 1); i++) {
                intervals.erase(intervals.begin() + i);
            }
            if (lf == -1) {
                intervals.insert(intervals.begin(), tmp);
            } else {
                intervals.insert(intervals.begin() + max(lf, 0), tmp);
            }
        }

        return intervals;
    }
};
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution *s = new Solution();
    vector<Interval> v;
    Interval v1(1, 5);
    Interval v2(6, 8);
    v.push_back(v1);
    vector<Interval> ans = s->insert(v, v2);
    int ansLen = ans.size();

    debug(ansLen);
    for (int i = 0; i < ansLen; i++) {
        printf("%d %d\n", ans[i].start, ans[i].end);
    }

    return 0;
}

