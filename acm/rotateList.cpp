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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL) {
            return NULL;
        }
        if (k == 0) {
            return head;
        }
        int len = 0;
        
        ListNode *q = head;
        while (q != NULL) {
            q = q->next;
            len++;
        }
        if (k > len) {
            k = k % len;
        }
        if (k == 0) {
            return head;
        }
        q = head;
        ListNode *tail, *p, *t;

        t = q->next;
        q->next = NULL;
        p = q;
        q = t;
        while (q != NULL) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        head = p;
        q = p;


        k--;
        t = q->next;
        q->next = NULL;
        p = q;
        q = t;

        while (k--) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }

        head = p;

        
        if (q != NULL) {
            t = q->next;
            q->next = NULL;
            p = q;
            q = t;
            while (q != NULL) {
                t = q->next;
                q->next = p;
                p = q;
                q = t;
            }
            tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = p;
        }

        return head;
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

    ListNode *node;
    for (int i = 2; i < 3; i++) {
        node = new ListNode(i);
        node->next = q->next;
        q->next = node;
        q = q->next;
    }

    ListNode *h = head;
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }
    h = s.rotateRight(head, 2);
    
    here;
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }
    return 0;
}

