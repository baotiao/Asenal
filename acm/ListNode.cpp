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
#define N 1600
#define PRIME 999983


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int listLen = 0;
        ListNode *p = head;
        while (p != NULL) {
            p = p->next;
            listLen++;
        }
        if (n > listLen) {
            return head;
        }
        if (n == listLen) {
            return head->next;
        }
        int cnt = listLen - n;
        p = head;
        ListNode *q;
        cnt--;
        while (cnt--) {
            p = p->next;
        }

        q = p->next;
        p->next = q->next;

        return head;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    ListNode *head = new ListNode(1);
    head->next = NULL;
    ListNode *q;
    q = head;

    Solution s;

    ListNode *node = new ListNode(2);
    node->next = q->next;
    q->next = node;
    q = q->next;

    node = new ListNode(3);
    node->next = q->next;
    q->next = node;
    q = q->next;
    
    ListNode *h = head;
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }
    h = s.removeNthFromEnd(head, 2);
    
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }
    return 0;
}

