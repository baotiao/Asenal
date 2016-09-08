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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
#define N 10000
#define PRIME 999983


int mp[N][N];
int status[N];
int sbak[N];


/*
 * 初始网络构建
 */
int origin = 1;
int ave_du = 4;
int n = N;

enum Status {
  kS = 0, // 未感染
  kI = 1, // 感染
  kR = 2 // 康复
};

/*
 * 感染概率, 百分比
 */
int grl = 10;
double dgrl = 0.1;

/*
 * 康复的概率
 */
int kfl = 20;

void Build()
{
/*
 * 初始化这个图
 */
  clr(mp, 0);
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < ave_du; j++) {
      tmp = rand() % N;
      /*
       * debug(tmp);
       */

      if (i == tmp) {
        continue;
      }
      mp[i][tmp] = 1;
      mp[tmp][i] = 1;
    }
  }

  /*
   * 初始化每一个节点的状态
   */
  clr(status, 0);

  status[0] = 1;

}

void Print()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", mp[i][j]);
    }
    printf("\n");

  }
}

bool Judge()
{
  for (int i = 0; i < n; i++) {
    if (status[i] == 1) {
      return false;
    }
  }
  return true;
}

void Process()
{

  /*
   * 定义这个迭代的次数
   */
  int tmp = 10;

  int rn = 0;

  int cnt = 1;
  int cs = 0, ci = 0, cr = 0;

  printf("Tick, S, I, R\n");
  for (int i = 0; i < n; i++) {
    if (status[i] == 0) {
      cs++;
    } else if (status[i] == 1) {
      ci++;
    } else if (status[i] == 2) {
      cr++;
    }
  }

  printf("%d, %d, %d, %d\n", 0, cs, ci, cr);
  while (1) {

    for (int i = 0; i < n; i++) {
      sbak[i] = status[i];
    }

    for (int i = 0; i < n; i++) {
      if (status[i] == 0) {
        debug(i);
        rn = 0;
        for (int j = 0; j < n; j++) {
          if (mp[i][j] == 1 && status[j] == 1) {
            rn++;
          }
        }
        if (rn == 0) {
          continue;
        }
        debug(rn);
        int l = rand() % 100;
        double rt = (1 - pow((1 - dgrl), rn));
        int r = (1 - pow((1 - dgrl), rn)) * 100;
        debug(rt);
        debug(l);
        debug(r);
        if (l <= r) {
          sbak[i] = 1;
        }
      } else if (status[i] == 1) {
        if (rand() % 100 <= kfl) {
          sbak[i] = 2;
        }
      } else {
      }
    }
    for (int i = 0; i < n; i++) {
      status[i] = sbak[i];
    }

    cs = 0, ci = 0, cr = 0;
    for (int i = 0; i < n; i++) {
      if (status[i] == 0) {
        cs++;
      } else if (status[i] == 1) {
        ci++;
      } else if (status[i] == 2) {
        cr++;
      }
    }

    printf("%d, %d, %d, %d\n", cnt++, cs, ci, cr);
    if (Judge()) {
      break;
    }
  }
}

int main()
{

  srand(time(0));
  Build();

  // Print();

  Process();

  return 0;
}
