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

int main()
{
    //#ifdef DEBUG
    //freopen("a", "r", stdin);
    //#endif
    char a[100], b[100], c[100], d[100];
    double a1, b1, c1, d1;
    
    char h;
    scanf("%s %lf %s %lf %s %s ,[%c]", &a, &a1, &b, &b1, &c, &d, &h);
    double i1, i2;
    //scanf("%s[]%s", &a, &b);
    //printf("%s dddd%s\n", a, b);
    //debug(i1);
    //printf("%s %lf %s %lf %s %s %c", a, a1, b, b1, c, d, h);

    printf("%lf\n", a1);
    printf("%lf\n", b1);
    printf("%c\n", h);

    




    return 0;
}

