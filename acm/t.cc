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

template <typename T>
struct M;

template <>
struct M <int>
{
};
int main()
{
    vector<vector<int> > vv;
    vector<int> v;
    v.push_back(1);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(4);

    vv.push_back(v);

    vector<vector<int> >::iterator iter;
    iter = find(vv.begin(), vv.end(), v1);

    if (iter == vv.end()) {
        printf("not find\n");
    } else {
        printf("found\n");
    }

    return 0;
}

