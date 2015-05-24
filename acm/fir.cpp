//test git
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
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
typedef long long lld; 
using namespace std; 
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

#define PREFIX_SMAP_BUFLEN (0x01000000 / 8)
typedef struct _mb_map_t
{
    u_int bitlen;  //位长度
    u_int ilen;    //整数个数
    u_int bytelen; //字节个数.
    int pdata[0];
} mb_map_t;

#define MB_ZERO(pmb)    _MB_ZERO(pmb) 
#define MB_SET(bit_pos,pmb) _MB_SET(bit_pos, pmb)
#define MB_ISSET(bit_pos,pmb) _MB_ISSET(bit_pos, pmb)
#define MB_CLR(bit_pos,pmb)  _MB_CLR(bit_pos, pmb)

/**下面是位操作的一些函数, 是MB系列使用 */
#define _MB_BITS   (8 * sizeof (int))   //得到一个整数的bit位数
#define _MB_SET(n, p)  ((p)->pdata[(n)/_MB_BITS] |= ((int)1 << ((n) % _MB_BITS)))
#define _MB_CLR(n, p)    ((p)->pdata[(n)/_MB_BITS] &= ~((int)1 << ((n) % _MB_BITS)))
#define _MB_ISSET(n, p)  ((p)->pdata[(n)/_MB_BITS] & ((int)1 << ((n) % _MB_BITS)))
#define _MB_ZERO(p)      bzero((p)->pdata, (p)->bytelen )
#define PREFIX_SMAP_STRLEN 3
#define PREFIX_SMAP_BUFLEN (0x01000000 / 8)

void prefix_smap_add(mb_map_t *pbitmap, const char *pstr)
{
    char buf[4];
    int *value = (int *)buf;
    int slen = strlen(pstr);
    slen = slen > PREFIX_SMAP_STRLEN ? PREFIX_SMAP_STRLEN : slen;
    for(int i=1; i<= slen; i++) {
        *value = 0;
        memcpy(buf, pstr, i); 
        printf("%lu\n", (*value) / _MB_BITS);
        printf("%d\n", (int)1 << ((*value) % _MB_BITS));
        MB_SET((*value), (pbitmap));
    }   
}
typedef struct _node {
    int num;
    char name[10];
}node;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    set<int> s1 = s;
    printf("%d\n", s.size());
    return 0;
}
