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
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 1600010
#define PRIME 999983

int f[N];
int get_fn(int n)
{
    if (f[n] != -1) {
        return f[n];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += get_fn(i) * get_fn(n - 1 - i);
    }
    f[n] = sum;
    return f[n];
}


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    printf("%d %d\n", rand(), rand());
    clr(f, -1);
    f[0] = 1;
    f[1] = 1;

    get_fn(10);
    
    for (int i = 0; i < 100; i++) {
        printf("%d\n", get_fn(i));
    }

    return 0;
}

