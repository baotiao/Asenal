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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (head == NULL) {
            return NULL;
        }
        ListNode *t, *e;
        int num = 1;
        int flag = 0;
        ListNode *p = head;
        ListNode *q;
        ListNode *ori;
        while (num < n) {
            q = p->next;
            if (num + 1 == m) {
                flag = 1;
                t = p;
            } else if (num + 1 == n) {
                flag = 0;
                e = p;
            }
            ori = p;
            q = q->next;
            p = q;

            if (flag == 1) {
                q->next = ori;
            }
        }
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

