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
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[k] = A[i];
                i--;
            } else {
                A[k] = B[j];
                j--;
            }
            k--;
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};

// 5 8  11 12 13   5 8 11
// 1 2 6 10
//
// 1 2 3  3 1 2 2 3
// 2 5 6

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;

    int A[9] = {5, 8, 11, 12, 13};
    int B[4] = {1, 2, 6, 10};
    s.merge(A, 5, B, 4);

    return 0;
}
