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
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <deque>
#include <set>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <cstdint>
#include <inttypes.h>
#include <sys/time.h>
#include <iomanip>

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

uint64_t NowMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<uint64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    uint64_t t1 = (uint64_t)(NowMicros() * 1e-6);
    cout << (uint64_t)(NowMicros() * 1e-6) << " " << NowMicros() << endl;
    cout << 100 * 1e+6<< endl;

    cout << t1 / 86400 << " " << t1 % 86400 << endl;
    uint64_t expire_time_ = (uint64_t)(NowMicros() * (1e-6)) - ((uint64_t)(NowMicros() * (1e-6)) % 86400) + 86400;
    cout << expire_time_  << endl;
    
    printf("%.2d\n", 1); // 这里是把日期里面1 输出成01的方法
 
    time_t timer;
    time(&timer);

    struct tm *t;
    t = gmtime(&timer);
    t->tm_hour += 8; // 这里+8 是换算成东8区
    mktime(t); // 然后用mktime重新算一下时间
    


    // 这里的时间tm_mon是月, 默认是从0开始所以要+1

    cout << t->tm_year + 1900 << " " << t->tm_mon + 1<< " " << t->tm_mday<< " " << t->tm_hour 
         << " " << t->tm_min << endl;
    return 0;
}

