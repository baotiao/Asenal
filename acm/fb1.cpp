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
#ifdef DEBUG1
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 101000
#define PRIME 999983
int m[N];
int h[N];
int flag[N];
int hlen;
int f1[N];
int add[N];
bool hcmp(int a, int b)
{
    return a > b;
}


int main()
{
    #ifdef DEBUG
    freopen("c", "r", stdin);
    freopen("b", "w", stdout);
    #endif
    int T;
    scanf("%d", &T);
    int cas = 1;
    int ans;
    while (T--) {
        debug(T);
        int n, k;
        lld a, b, c, r;
        scanf("%d%d", &n, &k);
        scanf("%lld%lld%lld%lld", &a, &b, &c, &r);
        clr(flag, 0);
        m[0] = a;
        if (m[0] <= k) {
            flag[m[0]] = 1;
        }
        debug("here");
        for (int i = 1; i < k; i++) {
            lld tmp = (b * (lld)m[i - 1] + c) % r;
            m[i] = tmp;
            //m[i] = (b * m[i - 1] + c) % r;
            //m[0] = 2;
            //m[1] = 5;
            //m[2] = 0;
            //m[3] = 6;
            if (m[i] <= k) {
                debug(m[i]);
                flag[m[i]] = 1;
            }
        }
        hlen = 0;
        debug("here");
        for (int i = 0; i <= k; i++) {
            if (flag[i] == 0) {
                debug(i);
                h[hlen++] = i;
                push_heap(h, h + hlen, hcmp);
            }
        }
        
        clr(f1, 0);
        clr(add, 0);
        debug("here");
        for (int i = k - 1; i >= 0; i--) {
            if (m[i] <= k && f1[m[i]] == 0) {
                add[i] = 1;
                f1[m[i]] = 1;
            }
        }
            

        debug(hlen);
        int start = 0;
        for (int i = k - 1; i >= 0; i--) {
            if (m[i] > k) {
                start = i;
                break;
            }
        }
        start++;
        debug(start);
        
        debug("here");
        int find_z = 0;
        int mlen = k;
        for (int i = 0; i < start; i++) {
            m[mlen++] = h[0];
            pop_heap(h, h + hlen, hcmp);
            hlen--;
            if (m[mlen - k - 1] <= k && add[i] == 1) {
                h[hlen++] = m[mlen - k - 1];
                push_heap(h, h + hlen, hcmp);
            }
        }
        m[mlen++] = h[0];
        
        //while (1) {
        //    debug(h[0]);
        //    m[mlen++] = h[0];
        //    pop_heap(h, h + hlen, hcmp);
        //    hlen--;
        //    debug(hlen);
        //    if (hlen == 0) {
        //        break;
        //    }
        //    if (m[mlen - k - 1] <= k) {
        //        h[hlen++] = m[mlen - k - 1];
        //        push_heap(h, h + hlen, hcmp);
        //    }
        //    sleep(0.5);
        //}
        debug(start);
        for (int i = start; i < mlen; i++) {
            debug(m[i]);
        }
        n -= start;
        int mod = ((n - 1) + 2 * (k + 1)) % (k + 1);
        ans = m[start + mod];
        printf("Case #%d: %d\n", cas++, ans);
        
    }

    return 0;
}
