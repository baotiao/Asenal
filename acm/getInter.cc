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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
void printP(ListNode *p)
{
    while (p != NULL) {
        debug(p->val);
        p = p->next;
    }
}
class Solution
{
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *p, *q;
        ListNode *f, *s;
        int ca = 0, cb = 0;
        p = headA;
        while (p->next != NULL) {
            ca++;
            p = p->next;
        }
        q = headB;
        while (q->next != NULL) {
            cb++;
            q = q->next;
        }
        if (p != q) {
            return NULL;
        }
        p = headA;
        q = NULL;
        while (p != NULL) {
            s = p->next;
            p->next = q;
            q = p;
            p = s;
        }
        ListNode* tail = q;
        
        p = headB;
        int cc = 0;
        while (p != NULL) {
            cc++;
            p = p->next;
        }
        debug(ca);
        debug(cb);
        debug(cc);
        int len = ((ca + cb) - (cc - 1)) / 2;

        p = tail;
        q = NULL;
        while (p != NULL) {
            s = p->next;
            p->next = q;
            q = p;
            p = s;
        }

        int t = cb - len;
        p = headB;
        while (t--) {
            p = p->next;
        }
        return p;

    }

};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    ListNode *head = new ListNode(1);
    head->next = NULL;
    ListNode *q;
    q = head;

    Solution s;

    ListNode *head1 = new ListNode(100);
    head1->next = NULL;

    ListNode *node;
    for (int i = 2; i < 5; i++) {
        node = new ListNode(i);
        if (i == 2) {
            head1->next = node;
        }
        node->next = q->next;
        q->next = node;
        q = q->next;
    }
    
    // printP(head1);
    // printP(head);
    ListNode *res = s.getIntersectionNode(head, head1);
    printP(res);
    return 0;
}

