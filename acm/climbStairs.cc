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
/*
 * 1 2 3 4 5   5 -> 3
 * 2 3
 * 2
 * 4 5
 * 3
 * 2 3
 * 6 2
 */
public:
    ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode *one = head;
		ListNode *two = head;
		int cnt1 = 0;
		int cnt2 = 0;
		while (1) {
			cnt1++;
			if (two->next == NULL) {
				return NULL;
			}
			if (two->next == one) {
				break;
			}
			cnt2++;
			two = two->next;
			if (two->next == NULL) {
				return NULL;
			}
			if (two->next == one) {
				break;
			}
			cnt1++;
			one = one->next;
		}
		int cnt = cnt2 - cnt1;
		while (cnt) {
			one = one->next;
			cnt--;
		}
	}
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    Solution s;

    return 0;
}
