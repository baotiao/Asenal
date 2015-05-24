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
            // Note: The Solution object is instantiated only once and is reused by each test case.

            if (head == NULL) {
                return NULL;
            }

            ListNode *h1, *t1;
            ListNode *h2, *t2;
            h2 = NULL;
            t2 = NULL;
            h1 = head;
            ListNode *p = head;
            int len = 0;
            while (p != NULL) {
                len++;
                p = p->next;
            }
            k = k%len;
            if (k == 0) {
                return head;
            }
            int f = len - k;
            p = head;
            if (f == 0) {
                return h1;
            }

            

            while (f--) {
                t1 = p;
                p = p->next;
            }
            h2 = p;
            while (p->next != NULL) {
                p = p->next;
            }
            t2 = p;
            t2->next = h1;
            t1->next = NULL;
            return h2;
            
        }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    ListNode *root = new ListNode(1);
    ListNode *h = root;
    ListNode *h1 = root;
    for (int i = 1; i < 2; i++) {
        ListNode *p = new ListNode(i);
        p->next = NULL;
        root->next = p;
        root = root->next;
    }
    //root->next = NULL;
    
    while (h != NULL) {
        debug(h->val);
        h = h->next;
    }
    Solution s;
    root = s.rotateRight(h1->next, 1);
    for (int i = 1; i < 6; i++) {
        debug(root->val);
        root = root->next;
    }
    
    return 0;
}

