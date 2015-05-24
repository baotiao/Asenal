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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *ans = new ListNode(10);
        ans->next = head;
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != NULL) {
            if (q->val == p->val) {
                q = q->next;
                p->next = q;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        return ans->next;
        
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

    node = new ListNode(3);
    node->next = q->next;
    q->next = node;
    q = q->next;



    ListNode *h = head;
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }

    h = s.deleteDuplicates(head);
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }
    return 0;
}
