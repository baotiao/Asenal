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
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

class A 
{
    public:
    A() { puts("A()"); }
    A(int v) { puts("A(int)"); }
    ~A() { puts("~A()"); }
    A& operator=(const A& rhs) { 
        puts("Aoperator=()");
        return *this;
    }
    A(const A& rhs) { 
        puts("Copy=()");
    }
};

class X
{
    public:
    X(int v) { a = v; }
    X(long v) : a(v) { }

    A a;
};


int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    puts("bad style");
    X slow(int(2)); }
    puts("good style");
    { X fast(long(2)); }

    puts("test copy construction");
    { 
        X a1(long(2));
        X a2(a1);
    }

    int T;
    return 0;
}
