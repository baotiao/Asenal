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
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (A[i] > B[j]) {
                for (int k = m; k > i; k--) {
                    A[k] = A[k - 1];
                }
                A[i] = B[j];
                j++;
                m++;
            } else {
                i++;
            }
        }
        while (j < n) {
            A[m++] = B[j];
            j++;
        }
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution s;
    int a[10] = {1, 3, 5, 4, 2};
    int b[5] = {2, 4, 6, 1, 1};
    s.merge(a, 5, b, 5);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

