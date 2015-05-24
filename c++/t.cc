#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <list>
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

struct node {
    int a;
    int b;
};

int main()
{

    node n;
    n.a = 1;
    n.b = 2;
    cout << &(n) << endl;
    cout << &(n.a) << endl;
    cout << &(n.b) << endl;

    vector<int> v;
    v.push_back(1);
    cout << v.data() << endl;
    cout << &(v[0]) << endl;
    cout << &v << endl;


    return 0;
}

