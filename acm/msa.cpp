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
                m++;
                j++;
                i++;
            } else {
                i++;
            }
        }
        while (j < n) {
            A[m++] = B[j++];
        }
        //for (int i = 0; i < m; i++) {
        //    printf("%d\n", A[i]);
        //}
    }
};
int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution s;
    int a[10], b[10];
    a[0] = 1;
    a[1] = 3;
    b[0] = 2;
    b[1] = 4;
    s.merge(a, 2, b, 2);
    return 0;
}

