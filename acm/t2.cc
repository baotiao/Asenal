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
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

char *pool_;
int pool_len_;
inline void MovePoint(const char *src, int distance)
{
    if (pool_len_ < distance)
    {
        pool_len_ = 100;
    }
    memcpy(pool_, src, distance);
    for (int i = 0; i < 7; i++) {
        printf("%d\n", pool_[i]);
    }
    pool_ += distance;
    pool_len_ -= distance;
}

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    pool_ = (char*) malloc(sizeof(char) * 100);
    pool_len_ = 6;
    MovePoint("\x00\x00\x00\x00\x00\x00", 7);
    return 0;
}

