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
#define N 110
#define PRIME 999983

struct node {
    //node (int _t, int _w, double _k) {
    //    t = _t;
    //    w = _w;
    //    k = _k;
    //};
    int t, w;
    double k;
}a[N];

bool cmp(node a, node b) {
    return a.k > b.k;
}


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    int n;
    int sumt, sumw;
    while (scanf("%d", &n) != EOF) {
        sumt = 0, sumw = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i].t, &a[i].w);
            a[i].k = (double)a[i].t / (double)a[i].w;
            sumt += a[i].t;
        }
        sort(a, a + n, cmp);
        int tmpt, tmpw;
        for (int i = 0; i < n; i++) {
            debug(a[i].t);
            debug(a[i].w);
            if (sumw + a[i].w <= sumt - a[i].t) {
                sumw += a[i].w;
                sumt -= a[i].t;
            } else {
                //break;
            }
        }
        printf("%d\n", sumt);
    }

    return 0;
}

