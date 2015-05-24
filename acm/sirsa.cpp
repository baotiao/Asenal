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
    int binary_search(int A[], int left, int right, int target)
    {
        if (left == right) {
            if (A[left] == target) {
                return left;
            } else {
                return -1;
            }
        }

        int mid = (left + right) / 2;
        if (A[left] < A[mid]) {
            if (A[left] <= target && target <= A[mid]) {
                return binary_search(A, left, mid, target);
            }
        } else {
            return binary_search(A, left, mid, target);
        }

        if (A[mid + 1] < A[right]) {
            if (A[mid + 1] <= target && target <= A[right]) {
                return binary_search(A, mid + 1, right, target);
            } else {
                return -1;
            }
        } else {
            return binary_search(A, mid + 1, right, target);
        }
        return -1;
    }

    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int ans = binary_search(A, 0, n, target);
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    return 0;
}

