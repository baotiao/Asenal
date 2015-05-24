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

	/*
	 * 1, 2, 6, 99, 100
	 * 3, 5, 7, 8, 11, 12, 14, 22, 33, 34, 44, 55, 66, 77, 88, 89, 90, 91, 92
	 */

	double find1(int num, int B[], int n)
	{
		if (n % 2 == 1) {
			debug(num);
			debug(n);
			if (num == B[n / 2]) {
				return num;
			} else if (num < B[n / 2] && num > B[n / 2 - 1]) {
				return (double)(B[n / 2] + num) / 2;
			} else if (num < B[n / 2] && num < B[n / 2 - 1]) {
				return (double)(B[n / 2] + B[n / 2 - 1]) / 2;
			} else if (num > B[n / 2] && num < B[n / 2 + 1]) {
				debug(B[n / 2]);
				debug(num);
				return (double)(B[n / 2] + num) / 2;
			} else if (num > B[n / 2] && num > B[n / 2 + 1]) {
				return (double)(B[n / 2] + B[n / 2 + 1]) / 2;
			}
		} else {
			if (num >= B[n / 2 - 1] && num <= B[n / 2]) {
				return num;
			} else if (num < B[n / 2 - 1]) {
				return B[n / 2 - 1];
			} else {
				return B[n / 2];
			}
		}
	}
	
	double find2(int n1, int n2, int B[], int n)
	{
		int l, r;
		if (n % 2 == 1) {
			if (n1 <= B[n / 2] && n2 >= B[n / 2]) {
				return B[n / 2];
			} else if (n2 < B[n / 2]) {
				if (n2 < B[n / 2 - 1]) {
					return B[n / 2 - 1];
				} else {
					return n2;
				}
			} else if (n1 >= B[n / 2]) {
				if (n1 >= B[n / 2 + 1]) {
					return B[n / 2 + 1];
				} else {
					return n1;
				}
			}
		} else {
			if (n2 <= B[n / 2 - 1]) {
				return (double)(B[n / 2 - 1] + max(B[n / 2 - 2], n2)) / 2;
			} else if (n1 >= B[n / 2]) {
				debug(n1);
				debug2(B[n / 2 + 1], n1);
				debug(B[n / 2]);
				return (double)(B[n / 2]  + min(B[n / 2 + 1], n1)) / 2;
			} else if (n2 <= B[n / 2]) {
				return (double)(max(B[n / 2 - 1], n1) + n2) / 2;
			} else if (n1 >= B[n / 2 - 1]) {
				return (double)(n1 + min(B[n / 2], n2)) / 2;
			} else if (n2 >= B[n / 2]) {
				return (double)(B[n / 2] + max(B[n / 2 - 1], n1)) / 2;
			} else if (n1 <= B[n / 2 - 1]) {
				return (double)(B[n / 2 - 1] + min(B[n / 2], n2)) / 2;
			}
		}
	}
	double findRes(int A[], int m, int B[], int n)
	{
		debug2(m, n);
		if (m == 0 && n % 2 == 0) {
			return (double)(B[n / 2] + B[n / 2 - 1]) / 2;
		} else if (m == 0 && n % 2 == 1) {
			return B[n / 2];
		} else if (n == 0) {
			return findRes(B, n, A, m);
		} else if (m == 1 && n == 1) {
			return (double)(A[0] + B[0]) / 2;
		} else if (m == 1) {
			return find1(A[0], B, n);
		} else if (n == 1) {
			return find1(B[0], A, m);
		} else if (m == 2 && n == 2) {
			debug2(A[0], A[1]);
			debug2(B[0], B[1]);
			return (double)((double)max(A[0], B[0]) + (double)min(A[1], B[1])) / 2;
		} else if (m == 2) {
			return find2(A[0], A[1], B, n);
		} else if (n == 2) {
			return findRes(B, n, A, m);
		}
		
		int l, r;
		debug2(m, n);
		if (A[m / 2] <= B[n / 2]) {
			l = (m - 1)/ 2;
			r = n - (n / 2 + 1);
			debug(l);
			debug(r);
			if (l < r) {
				return findRes(A + l, m - l, B, n - l);
			} else {
				return findRes(A + r, m - r, B, n - r);
			}
		} else {
			return findRes(B, n, A, m);
		}

	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		return findRes(A, m, B, n);
		
	}

};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;
	int A[] = {1, 5, 6, 7};
	int B[] = {2, 3, 4, 8, 9, 10};
	double ans = s.findMedianSortedArrays(A, 4, B, 6);
	debug(ans);

    return 0;
}
