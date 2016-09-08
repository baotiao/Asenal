#include <iostream> 
#include <cstdio> 
#include <cstdlib>
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
#include <unordered_set>
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
#define N 16000010
#define PRIME 999983



int main()
{

  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  for (int i = 0; i < v.size(); i++) {
    debug(v.size());
    v.erase(v.begin() + 2, v.begin() + 3);
  }

  for (int i = 0; i < v.size(); i++) {
    printf("%d\n", v[i]);
  }


  return 0;
}
