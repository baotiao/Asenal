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

inline int getp(int fenmu = 100) {
  return rand() % fenmu;
}

inline bool cp(double p, int fenmu = 100) {
  if ((int)(p * 100) > getp(fenmu)) {
    return true;
  }
  return false;
}

inline bool cp(int p, int fenmu = 100) {
  if (p > getp(fenmu)) {
    return true;
  }
  return false;
}

int main()
{
  
  srand(time(0));
  double p = exp(0.5) * 0.1;
  printf("%lf\n", p);




  return 0;
}

