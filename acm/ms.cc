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
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

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
    int maxPoints(vector<Point>& points)
    {
        

        int len = points.size();
        if (len == 0) {
            return 0;
        }
        int ans = 0;
        int cnt = 0;
        int tMax = 0;
        int vertical = 0;
        for (int i = 0; i < len; i++) {
            map<double, int> slope;
            slope.clear();
            cnt = 0;
            tMax = 0;
            vertical = 0;
            for (int j = i + 1; j < len; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    debug("if1");
                    cnt++;
                } else if (points[i].x == points[j].x) {
                    debug("if2");
                    vertical++;
                    tMax = max(tMax, vertical);
                } else {
                    double sl = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
                    debug(sl);
                    slope[sl]++;
                    tMax = max(tMax, slope[sl]);
                }
            }
            ans = max(ans, tMax + cnt);
        }
        debug(ans + 1);
        return ans + 1;
    }

};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
    vector<Point> vp;
    vp.push_back(Point(0, 0));
    vp.push_back(Point(1, 1));
    vp.push_back(Point(1, -1));
    vp.push_back(Point(3, 1));
    vp.push_back(Point(6, 2));
    vp.push_back(Point(12, 4));
    s.maxPoints(vp);
    // ababcd
    // -1 -1 0 1 -1 -1

    return 0;
}
