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

class Solution {
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
public:

    int binary_serach(int l, int r, vector<int> &numbers, int t)
    {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (t == 685) {
                debug(mid);
            }
            if (numbers[mid] < t) {
                l = mid + 1;
            } else if (numbers[mid] > t) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return l;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
       vector<int> ans;
       vector<int> origin = numbers;
       sort(numbers.begin(), numbers.end());
       for (int i = 0; i < numbers.size(); i++) {
           debug(numbers[i]);
       }
       int i, j;
       int b = 0;
       debug(target);
       for (i = 0; i < numbers.size(); i++) {
           j = binary_serach(i + 1, numbers.size() - 1, numbers, target - numbers[i]);
           debug(i);
           debug(j);
           if (numbers[i] + numbers[j] == target) {
               debug(numbers[i]);
               debug(numbers[j]);
               for (int k = 0; k < origin.size(); k++) {
                   if (origin[k] == numbers[i]) {
                       ans.push_back(k + 1);
                       if (b == 1) {
                           return ans;
                       }
                       b = 1;
                   } else if (origin[k] == numbers[j]) {
                       ans.push_back(k + 1);
                       if (b == 1) {
                           return ans;
                       }
                       b = 1;
                   }
               }
           }
       }
       return ans;

    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    Solution s;
    // int vv[] = {591,955,829,805,312,83,764,841,12,744,104,773,627,306,731,539,349,811,662,341,465,300,491,423,569,405,508,802,500,747,689,506,129,325,918,606,918,370,623,905,321,670,879,607,140,543,997,530,356,446,444,184,787,199,614,685,778,929,819,612,737,344,471,645,726};
    int vv[] = {3, 2, 4};
    vector<int> a(begin(vv), end(vv));
    debug(a.size());
    int t = 6;
    vector<int> v = s.twoSum(a, t);
    debug(v[0]);
    debug(v[1]);

    return 0;
}

