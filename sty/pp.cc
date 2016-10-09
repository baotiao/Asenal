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
#include <cstdlib>
#include "xdebug.h"

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
#define N 20000
#define PRIME 999983


int res[N];
int max_len = 0;
int step = 400;

int main(int argc, char **argv)
{
  string fname = argv[1];
  clr(res, 0);

  for (int j = 0; j < 100; j++) {
    char cname[100];
    snprintf(cname, sizeof(cname), "%s%d", fname.c_str(), j);
    freopen(cname, "r", stdin);

    string tmp;
    getline(std::cin, tmp);
    int a, b;
    int i = 0;
    while (scanf("%d, %d, %d, %d, %d", &a, &b, &a, &a, &a) != EOF) {
      res[i] += b;
      i++;
      max_len = max(max_len, i);
    }
    while (i < step) {
      res[i] += b;
      i++;
    }
  }
  for (int i = 0; i < max_len; i++) {
    printf("%d, %d\n", i, res[i] / 100);
  }
  return 0;
}
