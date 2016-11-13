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
#define N 2000
#define PRIME 999983


struct node {
  int r, ii, iv;
}res[N];
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
    int a, b, c, d;
    int i = 0;
    while (scanf("%d\t%d\t%d\t%d", &a, &b, &c, &d) != EOF) {
      res[i].r += b;
      res[i].ii += c;
      res[i].iv += d;
      i++;
      max_len = max(max_len, i);
    }
    while (i < step) {
      res[i].r += b;
      res[i].ii += c;
      res[i].iv += d;
      i++;
    }
  }
  for (int i = 0; i < max_len; i++) {
    printf("%d\t%d\t%d\t%d\n", i, res[i].r / 100, res[i].ii / 100, res[i].iv / 100);
  }
  return 0;
}
