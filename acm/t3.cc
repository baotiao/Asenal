#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stack>
#include <queue> 
#include <map>
#include <ctime>
#include <set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 1010
#define PRIME 999983

double fun(int n, int m, int r)
{
  printf("n = %d m = %d r = %d\n", n, m, r);
  if ((n == 0 || m == 0) && r > 0) {
    return 1;
  } else if ((n == 0 || m == 0) && r <= 0) {
    return 0;
  }
  return ((double)n / (double)(n + m))* fun((n - 1), m, r - n - m) + ((double)m / (double)(m + n)) * fun(n, m - 1, r);
}

int main () {

  double res = fun(5, 10, 57);
  printf("%f \n", res);
  return 0;
}
